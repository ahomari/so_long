/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:20:37 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/30 00:04:18 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	enemy_move_up(t_list *data)
{
	if (data->map[data->y_enemy - 1][data->x_enemy] == '0'
		|| data->map[data->y_enemy - 1][data->x_enemy] == 'P')
	{
		if (data->map[data->y_enemy - 1][data->x_enemy] == 'P')
			finish_game(data, 'B');
		data->map[data->y_enemy][data->x_enemy] = '0';
		data->y_enemy -= 1;
		data->map[data->y_enemy][data->x_enemy] = 'B';
	}
}

void	enemy_move_down(t_list *data)
{
	if (data->map[data->y_enemy + 1][data->x_enemy] == '0'
		|| data->map[data->y_enemy + 1][data->x_enemy] == 'P')
	{
		if (data->map[data->y_enemy + 1][data->x_enemy] == 'P')
			finish_game(data, 'B');
		data->map[data->y_enemy][data->x_enemy] = '0';
		data->y_enemy += 1;
		data->map[data->y_enemy][data->x_enemy] = 'B';
	}
}

void	enemy_move_right(t_list *data)
{
	if (data->map[data->y_enemy][data->x_enemy + 1] == '0'
		|| data->map[data->y_enemy][data->x_enemy + 1] == 'P')
	{
		if (data->map[data->y_enemy][data->x_enemy + 1] == 'P')
			finish_game(data, 'B');
		data->map[data->y_enemy][data->x_enemy] = '0';
		data->x_enemy += 1;
		data->map[data->y_enemy][data->x_enemy] = 'B';
	}
}

void	enemy_move_left(t_list *data)
{
	if (data->map[data->y_enemy][data->x_enemy - 1] == '0'
		|| data->map[data->y_enemy][data->x_enemy - 1] == 'P')
	{
		if (data->map[data->y_enemy][data->x_enemy - 1] == 'P')
			finish_game(data, 'B');
		data->map[data->y_enemy][data->x_enemy] = '0';
		data->x_enemy -= 1;
		data->map[data->y_enemy][data->x_enemy] = 'B';
	}
}
