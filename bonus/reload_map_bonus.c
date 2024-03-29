/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:53:22 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/29 02:31:22 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_enemy(t_list *data)
{
	data->randem_num = rand() % 4;
	if (data->randem_num == 0)
		enemy_move_up(data);
	else if (data->randem_num == 1)
		enemy_move_down(data);
	else if (data->randem_num == 2)
		enemy_move_right(data);
	else if (data->randem_num == 3)
		enemy_move_left(data);
}

int	animation(t_list *data)
{
	static int	i = -1;

	i++;
	if (i < 10)
		data->index_enmy = 0;
	else if (i < 20)
		data->index_enmy = 1;
	else if (i < 30)
		data->index_enmy = 2;
	else if (i < 40)
		data->index_enmy = 3;
	else if (i < 50)
		data->index_enmy = 4;
	else
	{
		position_enemy(data);
		i = -1;
	}
	mlx_do_sync(data->mlx);
	reload_map(data);
	usleep(100);
	return (0);
}

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
	else if (data->map[i][j] == 'B')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->monster[data->index_enmy], j * 50, i * 50);
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
	data->nbr_move = ft_itoa(data->count_move);
	data->msg_move = ft_strjoin("You Moved ", data->nbr_move);
	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0xFFFFFF, data->msg_move);
	free(data->msg_move);
	free(data->nbr_move);
	mlx_loop_hook(data->mlx, animation, data);
}
