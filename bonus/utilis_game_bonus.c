/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:02:54 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/25 02:23:36 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	count_CEP(char **ptr, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (ptr[i])
	{
		j = 0;
		while(ptr[i][j])
		{
			if (ptr[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	position_player(char **ptr, int *x, int *y)
{
	int i;
	int j;
	
	i = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] == 'P')
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
}
void	sub_reload(t_list *data, char c, int i, int j)
{
	if (data->map[i][j] == 'P')
	{	
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, j * 50, i * 50);
		if (c == 'p')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, j * 50, i * 50);
		else if (c == 'r')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_right, j * 50, i * 50);
		else if (c == 'l')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_left, j * 50, i * 50);
		else if (c == 't')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_top, j * 50, i * 50);
		else if (c == 'd')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_down, j * 50, i * 50);
	}
	else if (data->map[i][j] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, j * 50, i * 50);
		if(data->count_C == 0)
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->door_open, j * 50, i * 50);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->door_close, j * 50, i * 50);
	}
}

void	reload_map(t_list *data, char c)
{
	int i;
	int j;
	
	i = -1;
	mlx_clear_window(data->mlx, data->mlx_win);
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_img, j * 50, i * 50);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, j * 50, i * 50);
			else if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, j * 50, i * 50);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->coins_img, j * 50, i * 50);
			}
			else
				sub_reload(data, c, i, j);
		}
	}
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, echap_exit, data);
}

void	get_img(t_list *data)
{
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &data->img_width, &data->img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm", &data->img_width, &data->img_height);
	data->coins_img = mlx_xpm_file_to_image(data->mlx, "textures/coin.xpm", &data->img_width, &data->img_height);
	data->door_close = mlx_xpm_file_to_image(data->mlx, "textures/door_close.xpm", &data->img_width, &data->img_height);
	data->door_open = mlx_xpm_file_to_image(data->mlx, "textures/door_open.xpm", &data->img_width, &data->img_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm", &data->img_width, &data->img_height);
	data->player_right = mlx_xpm_file_to_image(data->mlx, "textures/player_right.xpm", &data->img_width, &data->img_height);
	data->player_left = mlx_xpm_file_to_image(data->mlx, "textures/player_left.xpm", &data->img_width, &data->img_height);
	data->player_top = mlx_xpm_file_to_image(data->mlx, "textures/player_top.xpm", &data->img_width, &data->img_height);
	data->player_down = mlx_xpm_file_to_image(data->mlx, "textures/player_down.xpm", &data->img_width, &data->img_height);
	if (!data->wall_img || !data->floor || !data->coins_img || !data->door_close || !data->door_open 
		|| !data->player_img || !data->player_right || !data->player_left || !data->player_top || !data->player_down)
		msg_error(-2, "Error\n");
}