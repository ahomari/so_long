/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:02:54 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/29 03:06:06 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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

void	position_enemy(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'B')
			{
				data->x_enemy = j;
				data->y_enemy = i;
				move_enemy(data);
			}
			j++;
		}
		i++;
	}
}

void	**animation_init(t_list *data)
{
	data->monster = (void **)malloc(5 * sizeof(void *));
	if (!data->monster)
		msg_error(-2, "Error\n", data);
	data->monster[0] = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/frame_0.xpm", &data->img_width, &data->img_height);
	data->monster[1] = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/frame_1.xpm", &data->img_width, &data->img_height);
	data->monster[2] = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/frame_2.xpm", &data->img_width, &data->img_height);
	data->monster[3] = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/frame_3.xpm", &data->img_width, &data->img_height);
	data->monster[4] = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/frame_4.xpm", &data->img_width, &data->img_height);
	if (!data->monster[0] || !data->monster[1] || !data->monster[2]
		|| !data->monster[3] || !data->monster[4])
		msg_error(-2, "Error\nanimation_init Failed\n", data);
	return (data->monster);
}

void	get_img(t_list *data)
{
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/wall.xpm", &data->img_width, &data->img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/floor.xpm", &data->img_width, &data->img_height);
	data->coins_img = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/coin.xpm", &data->img_width, &data->img_height);
	data->door_close = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/door_c.xpm", &data->img_width, &data->img_height);
	data->door_open = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/door_o.xpm", &data->img_width, &data->img_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/player.xpm", &data->img_width, &data->img_height);
	data->player_right = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/player_r.xpm", &data->img_width, &data->img_height);
	data->player_left = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/player_l.xpm", &data->img_width, &data->img_height);
	data->player_top = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/player_t.xpm", &data->img_width, &data->img_height);
	data->player_down = mlx_xpm_file_to_image(data->mlx,
			"bonus/textures/player_d.xpm", &data->img_width, &data->img_height);
	data->monster = animation_init(data);
	if (!data->wall_img || !data->floor || !data->coins_img || !data->door_close
		|| !data->door_open || !data->player_img || !data->player_right
		|| !data->player_left || !data->player_top || !data->player_down)
		msg_error(-2, "Error\nget_img Failed\n", data);
}
