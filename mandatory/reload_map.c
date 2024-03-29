/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:01:49 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/29 02:30:14 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	reload_map2(t_list *data, int i, int j)
{
	if (data->map[i][j] == 'P')
	{
		if (data->direction == 'p')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->player_img, j * 50, i * 50);
		else if (data->direction == 'r')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->player_right, j * 50, i * 50);
		else if (data->direction == 'l')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->player_left, j * 50, i * 50);
		else if (data->direction == 'u')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->player_top, j * 50, i * 50);
		else if (data->direction == 'd')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->player_down, j * 50, i * 50);
	}
}

void	reload_map1(t_list *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->wall_img, j * 50, i * 50);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->coins_img, j * 50, i * 50);
	else if (data->map[i][j] == 'E')
	{
		if (data->count_c == 0)
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->door_open, j * 50, i * 50);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->door_close, j * 50, i * 50);
	}
	else
		reload_map2(data, i, j);
}

void	reload_map(t_list *data)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(data->mlx, data->mlx_win);
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->floor, j * 50, i * 50);
			reload_map1(data, i, j);
		}
	}
	ft_printf("You Moved %d Times\n", data->count_move);
}
