/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 02:41:13 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/30 01:45:54 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	finish_game(t_list *data, char c)
{
	data->count_move += 1;
	reload_map(data);
	if (c == 'E')
		ft_printf("You Win\n");
	else if (c == 'B')
		ft_printf("You Lost\n");
	ft_cleanup(data);
	exit(0);
}

void	move_up(t_list *data)
{
	if (data->map[data->y - 1][data->x] != '1')
	{
		if (data->map[data->y - 1][data->x] == 'E' && data->count_c == 0)
			finish_game(data, 'E');
		else if (data->map[data->y - 1][data->x] == 'B')
			finish_game(data, 'B');
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
			finish_game(data, 'E');
		else if (data->map[data->y + 1][data->x] == 'B')
			finish_game(data, 'B');
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
			finish_game(data, 'E');
		else if (data->map[data->y][data->x + 1] == 'B')
			finish_game(data, 'B');
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
			finish_game(data, 'E');
		else if (data->map[data->y][data->x - 1] == 'B')
			finish_game(data, 'B');
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
