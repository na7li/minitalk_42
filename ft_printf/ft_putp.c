/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:08:37 by mnahli            #+#    #+#             */
/*   Updated: 2024/11/28 09:16:16 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putp(unsigned long n)
{
	unsigned int	count;
	char			*str;

	count = 0;
	str = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_putp(n / 16);
		count += ft_putp(n % 16);
	}
	else
		count += ft_putchar(str[n % 16]);
	return (count);
}
