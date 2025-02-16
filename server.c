/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaouzi <sfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:57:17 by sfaouzi           #+#    #+#             */
/*   Updated: 2025/02/14 02:00:41 by sfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_exit(char *message)
{
	while (message && *message)
		write(2, message++, 1);
	exit(1);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		write(fd, str++, fd);
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	comp_id;
	static int	i;
	static char	c;

	(void)context;
	if (comp_id != info->si_pid)
	{
		i = 0;
		c = 0;
	}
	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	comp_id = info->si_pid;
	if (kill(info->si_pid, SIGUSR1) == -1)
		error_exit("Error: Failed to send acknowledgment signal\n");
	if (i == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	r;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n > 9)
	{
		r = n % 10;
		n = n / 10;
		ft_putnbr_fd(n, fd);
		r = r + 48;
		write(fd, &r, 1);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		r = n + 48;
		write(fd, &r, 1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error_exit("Error: Failed to set up SIGUSR1 handler\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		error_exit("Error: Failed to set up SIGUSR2 handler\n");
	while (1)
		pause();
	return (0);
}
