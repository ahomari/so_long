/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 02:41:13 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/29 01:55:53 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	finish_game(t_list *data)
{
	data->count_move += 1;
	reload_map(data);
	ft_printf("You Win\n");
	ft_cleanup(data);
	exit(0);
}

void	move_up(t_list *data)
{
	if (data->map[data->y - 1][data->x] != '1')
	{
		if (data->map[data->y - 1][data->x] == 'E' && data->count_c == 0)
			finish_game(data);
		else if (data->map[data->y - 1][data->x] == '0'
			|| data->map[data->y - 1][data->x] == 'C')
		{
			data->count_move += 1;
			if (data->map[data->y - 1][data->x] == 'C')
				data->count_c--;
			data->map[data->y][data->x] = '0';
			data->y -= 1;
			data->map[data->y][data->x] = 'P';
		}
	}
	data->direction = 'u';
}

void	move_down(t_list *data)
{
	if (data->map[data->y + 1][data->x] != '1')
	{
		if (data->map[data->y + 1][data->x] == 'E' && data->count_c == 0)
			finish_game(data);
		else if (data->map[data->y + 1][data->x] == '0'
			|| data->map[data->y + 1][data->x] == 'C')
		{
			data->count_move += 1;
			if (data->map[data->y + 1][data->x] == 'C')
				data->count_c--;
			data->map[data->y][data->x] = '0';
			data->y += 1;
			data->map[data->y][data->x] = 'P';
		}
	}
	data->direction = 'd';
}

void	move_right(t_list *data)
{
	if (data->map[data->y][data->x + 1] != '1')
	{
		if (data->map[data->y][data->x + 1] == 'E' && data->count_c == 0)
			finish_game(data);
		else if (data->map[data->y][data->x + 1] == '0'
			|| data->map[data->y][data->x + 1] == 'C')
		{
			data->count_move += 1;
			if (data->map[data->y][data->x + 1] == 'C')
				data->count_c--;
			data->map[data->y][data->x] = '0';
			data->x += 1;
			data->map[data->y][data->x] = 'P';
		}
	}
	data->direction = 'r';
}

void	move_left(t_list *data)
{
	if (data->map[data->y][data->x - 1] != '1')
	{
		if (data->map[data->y][data->x - 1] == 'E' && data->count_c == 0)
			finish_game(data);
		else if (data->map[data->y][data->x - 1] == '0'
			|| data->map[data->y][data->x - 1] == 'C')
		{
			data->count_move += 1;
			if (data->map[data->y][data->x - 1] == 'C')
				data->count_c--;
			data->map[data->y][data->x] = '0';
			data->x -= 1;
			data->map[data->y][data->x] = 'P';
		}
	}
	data->direction = 'l';
}
