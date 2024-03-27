/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:45:26 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/25 16:51:02 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	flood_fill(char **ptr, int pos_x, int pos_y, t_list *data)
{
	
	if ((ptr[pos_y][pos_x] == '0' || ptr[pos_y][pos_x] == 'P'))
		ptr[pos_y][pos_x] = '1';
	else if (ptr[pos_y][pos_x] == 'C')
	{
		ptr[pos_y][pos_x] = '1';
		data->count_C -= 1;
	}
	else if (ptr[pos_y][pos_x] == 'E')
	{
		ptr[pos_y][pos_x] = '1';
		data->count_E -= 1;
	}
	else if (ptr[pos_y][pos_x] == 'B')
	{
		ptr[pos_y][pos_x] = '1';
		data->count_I -= 1;
	}
	else
		return ;
	flood_fill(ptr, pos_x + 1, pos_y, data);
	flood_fill(ptr, pos_x - 1, pos_y, data);
	flood_fill(ptr, pos_x, pos_y + 1, data);
	flood_fill(ptr, pos_x, pos_y - 1, data);
}
