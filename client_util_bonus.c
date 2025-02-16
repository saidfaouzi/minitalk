/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_util_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaouzi <sfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:38:06 by sfaouzi           #+#    #+#             */
/*   Updated: 2025/02/14 02:48:24 by sfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	error_exit(char *message)
{
	while (message && *message)
		write(2, message++, 1);
	exit(1);
}
