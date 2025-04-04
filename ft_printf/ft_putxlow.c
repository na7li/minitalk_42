/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxlow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:59:12 by mnahli            #+#    #+#             */
/*   Updated: 2024/11/28 09:16:10 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putxlow(unsigned int n)
{
	int		count;
	char	*str;

	count = 0;
	str = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_putxlow(n / 16);
		count += ft_putxlow(n % 16);
	}
	else
		count += ft_putchar(str[n % 16]);
	return (count);
}
