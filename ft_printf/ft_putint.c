/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:15:18 by mnahli            #+#    #+#             */
/*   Updated: 2024/11/28 09:16:18 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putint(int n)
{
	unsigned int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		count = 1;
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putint(n / 10);
		count += ft_putint(n % 10);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}
