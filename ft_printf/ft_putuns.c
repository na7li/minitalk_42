/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:43:30 by mnahli            #+#    #+#             */
/*   Updated: 2024/11/28 09:16:11 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putuns(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putuns(n / 10);
		count += ft_putuns(n % 10);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}
