/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:07:39 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/25 02:22:19 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

void	ft_putnbr_long(long nbr, int *count)
{
	if (nbr < 0)
	{
		ft_putchar('-', count);
		ft_putnbr_long(nbr * -1, count);
	}
	else if (nbr <= 9)
	{
		ft_putchar(nbr + 48, count);
	}
	else
	{
		ft_putnbr_long(nbr / 10, count);
		ft_putnbr_long(nbr % 10, count);
	}
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}
