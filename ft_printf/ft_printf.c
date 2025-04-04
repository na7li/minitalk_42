/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:37:38 by mnahli            #+#    #+#             */
/*   Updated: 2024/11/28 13:47:23 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_isspecifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

static int	ft_check(va_list args, char c)
{
	unsigned int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		count = ft_putint(va_arg(args, int));
	else if (c == 'u')
		count = ft_putuns(va_arg(args, unsigned int));
	else if (c == 'x')
		count = ft_putxlow(va_arg(args, unsigned int));
	else if (c == 'X')
		count = ft_putxup(va_arg(args, unsigned int));
	else if (c == 'p')
	{
		count = write(1, "0x", 2);
		count += ft_putp(va_arg(args, unsigned long long));
	}
	else if (c == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				i;
	int				count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			if (ft_isspecifier(format[i]))
				count += ft_check(args, format[i]);
			else
				count += ft_putchar(format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
