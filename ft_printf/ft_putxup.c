/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:07:29 by mnahli            #+#    #+#             */
/*   Updated: 2024/11/28 09:16:06 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putxup(unsigned int n)
{
	int		count;
	char	*str;

	count = 0;
	str = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_putxup(n / 16);
		count += ft_putxup(n % 16);
	}
	else
		count += ft_putchar(str[n % 16]);
	return (count);
}
