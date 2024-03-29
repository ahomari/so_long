/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:45:26 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/29 02:17:18 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	flood_fill(t_list *data, int pos_x, int pos_y)
{
	if ((data->ptr[pos_y][pos_x] == '0' || data->ptr[pos_y][pos_x] == 'P'))
		data->ptr[pos_y][pos_x] = '1';
	else if (data->ptr[pos_y][pos_x] == 'C')
	{
		data->ptr[pos_y][pos_x] = '1';
		data->count_c -= 1;
	}
	else if (data->ptr[pos_y][pos_x] == 'E')
	{
		data->ptr[pos_y][pos_x] = '1';
		data->count_e -= 1;
	}
	else
		return ;
	flood_fill(data, pos_x + 1, pos_y);
	flood_fill(data, pos_x - 1, pos_y);
	flood_fill(data, pos_x, pos_y + 1);
	flood_fill(data, pos_x, pos_y - 1);
}
