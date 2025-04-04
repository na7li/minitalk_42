/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:18:51 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/04 11:24:05 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static char	c;
	static int				bit_i;

	c |= (signal == SIGUSR1);
	bit_i++;
	if (bit_i == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		bit_i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("Server's PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1337)
		pause();
	return (0);
}
