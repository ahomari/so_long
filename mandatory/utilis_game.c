/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:02:54 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/29 02:13:57 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_elm(char **ptr, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	position_player(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->ptr[i])
	{
		j = 0;
		while (data->ptr[i][j])
		{
			if (data->ptr[i][j] == 'P')
			{
				data->x = j;
				data->y = i;
			}
			j++;
		}
		i++;
	}
}

void	get_img(t_list *data)
{
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm", &data->img_width, &data->img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx,
			"textures/floor.xpm", &data->img_width, &data->img_height);
	data->coins_img = mlx_xpm_file_to_image(data->mlx,
			"textures/coin.xpm", &data->img_width, &data->img_height);
	data->door_close = mlx_xpm_file_to_image(data->mlx,
			"textures/door_close.xpm", &data->img_width, &data->img_height);
	data->door_open = mlx_xpm_file_to_image(data->mlx,
			"textures/door_open.xpm", &data->img_width, &data->img_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx,
			"textures/player.xpm", &data->img_width, &data->img_height);
	data->player_right = mlx_xpm_file_to_image(data->mlx,
			"textures/player_right.xpm", &data->img_width, &data->img_height);
	data->player_left = mlx_xpm_file_to_image(data->mlx,
			"textures/player_left.xpm", &data->img_width, &data->img_height);
	data->player_top = mlx_xpm_file_to_image(data->mlx,
			"textures/player_top.xpm", &data->img_width, &data->img_height);
	data->player_down = mlx_xpm_file_to_image(data->mlx,
			"textures/player_down.xpm", &data->img_width, &data->img_height);
	if (!data->wall_img || !data->floor || !data->coins_img || !data->door_close
		|| !data->door_open || !data->player_img || !data->player_right
		|| !data->player_left || !data->player_top || !data->player_down)
		msg_error(-2, "Error\nget_img Failed\n", data);
}
