/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:49:05 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/17 15:18:55 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_list *data)
{
	if (keycode == 126)
	{
		if (data->map[data->y - 1][data->x] == '0' || data->map[data->y - 1][data->x] == 'C')
		{
			if (data->map[data->y - 1][data->x] == 'C')
				data->C_count--;
			mlx_clear_window(data->mlx, data->mlx_win);
			data->map[data->y][data->x] = '0';
			data->y -= 1;
			data->map[data->y][data->x] = 'P';
			reload_map(data);
		}
		else if (data->map[data->y - 1][data->x] == 'E' && data->C_count == 0)
			exit(0);
			// move_player(data, keycode);
	}
	else if (keycode == 125)
	{
		if (data->map[data->y + 1][data->x] == '0' || data->map[data->y + 1][data->x] == 'C')
		{
			if (data->map[data->y + 1][data->x] == 'C')
				data->C_count--;
			mlx_clear_window(data->mlx, data->mlx_win);
			data->map[data->y][data->x] = '0';
			data->y += 1;
			data->map[data->y][data->x] = 'P';
			reload_map(data);
		}
		else if (data->map[data->y + 1][data->x] == 'E' && data->C_count == 0)
			exit(0);
			// move_player(data, keycode);
	}
	else if (keycode == 124)
	{
		if (data->map[data->y][data->x + 1] == '0' || data->map[data->y][data->x + 1] == 'C')
		{
			if (data->map[data->y][data->x + 1] == 'C')
				data->C_count--;
			mlx_clear_window(data->mlx, data->mlx_win);
			data->map[data->y][data->x] = '0';
			data->x += 1;
			data->map[data->y][data->x] = 'P';
			reload_map(data);
		}
		else if (data->map[data->y][data->x + 1] == 'E' && data->C_count == 0)
			exit(0);
			// move_player(data, keycode);
	}
	else if (keycode == 123)
	{
		if (data->map[data->y][data->x - 1] == '0' || data->map[data->y][data->x - 1] == 'C')
		{
			if (data->map[data->y][data->x - 1] == 'C')
				data->C_count--;
			mlx_clear_window(data->mlx, data->mlx_win);
			data->map[data->y][data->x] = '0';
			data->x -= 1;
			data->map[data->y][data->x] = 'P';
			reload_map(data);
		}
		else if (data->map[data->y][data->x - 1] == 'E' && data->C_count == 0)
			exit(0);
			// move_player(data, keycode);
	}
	return (0);
}

// 126 up; y - 1
// 125 down; y + 1
// 124 right  x +1 ;
// 123 left; x - 1