/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:38:32 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/29 01:38:46 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_format(va_list ap, int *count, const char format)
{
	if (format == '%')
		ft_putchar(format, count);
	else if (format == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (format == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (format == 'd' || format == 'i')
		ft_putnbr_long(va_arg(ap, int), count);
	else if (format == 'u')
		ft_putnbr_long(va_arg(ap, unsigned int), count);
	else
		ft_putchar(format, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (write(1, "", 0))
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				break ;
			i++;
			ft_format(ap, &count, format[i]);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}
