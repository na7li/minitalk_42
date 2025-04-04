/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:18:45 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/04 09:44:58 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t srv_pid, unsigned char c)
{
	unsigned char	tmp;
	int				bit;

	bit = 8;
	tmp = c;
	while (bit-- > 0)
	{
		tmp = c >> bit;
		if (tmp % 2 == 0)
			kill(srv_pid, SIGUSR2);
		else
			kill(srv_pid, SIGUSR1);
		usleep(79);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3)
	{
		ft_printf("The received parameters are not correct.\n");
		exit (1);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
		send_char(pid, av[2][i++]);
	send_char(pid, '\0');
	return (0);
}
