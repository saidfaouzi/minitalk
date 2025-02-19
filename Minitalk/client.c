/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaouzi <sfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:57:27 by sfaouzi           #+#    #+#             */
/*   Updated: 2025/02/14 02:15:56 by sfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_glob;

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	res;

	signe = 1;
	i = 0;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res *= 10;
		res = res + ((char)nptr[i] - 48);
		i++;
	}
	return (res * signe);
}

void	handle_response(int signum)
{
	(void)signum;
	g_glob = 1;
}

void	error_exit(char *message)
{
	while (message && *message)
		write(2, message++, 1);
	exit(1);
}

void	send_signals(int p_id, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_glob = 0;
		if (c & (1 << i))
		{
			if (kill(p_id, SIGUSR1) == -1)
				error_exit("Error: Failed to send SIGUSR1\n");
		}
		else
		{
			if (kill(p_id, SIGUSR2) == -1)
				error_exit("Error: Failed to send SIGUSR2\n");
		}
		i++;
		while (g_glob == 0)
			usleep(50);
	}
	usleep(100);
}

int	main(int ac, char *av[])
{
	int					p_id;
	char				*msg;
	struct sigaction	sa;
	int					i;

	if (ac != 3)
		error_exit("Usage: ./client <pid> <message>\n");
	p_id = ft_atoi(av[1]);
	if (p_id <= 0)
		error_exit("Error: Invalid PID\n");
	msg = av[2];
	if (!msg || !*msg)
		error_exit("Error: Empty message\n");
	sa.sa_handler = &handle_response;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error_exit("Error: Failed to set up SIGUSR1 handler\n");
	i = 0;
	while (msg[i])
		send_signals(p_id, msg[i++]);
	send_signals(p_id, '\0');
	return (0);
}
