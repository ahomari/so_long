/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 02:41:13 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/25 02:42:33 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	finish_game(t_list *data, char c)
{
	data->count_move += 1;
	ft_printf("You Moved %d Times\n", data->count_move);
	if (c == 'E')
	{
		ft_printf("You Win\n");
		ft_cleanup(data);
		exit(0);
	}
	else if (c == 'B')
		msg_error(-2, "Lost !!\n", data);
}

void	move_up(t_list *data)
{
	if (data->map[data->y - 1][data->x] != '1')
	{
		if (data->map[data->y - 1][data->x] == 'E' && data->count_C == 0)
			finish_game(data, 'E');
		else if (data->map[data->y - 1][data->x] == 'B')
			finish_game(data, 'B');
		else if (data->map[data->y - 1][data->x] == '0' || data->map[data->y - 1][data->x] == 'C')
		{
			data->count_move += 1;
			if (data->map[data->y - 1][data->x] == 'C')
				data->count_C--;
			data->map[data->y][data->x] = '0';
			data->y -= 1;
			data->map[data->y][data->x] = 'P';
		}
	}
	data->nbr_move = ft_itoa(data->count_move);
	data->direction = 'u';
}

void	move_down(t_list *data)
{
	if (data->map[data->y + 1][data->x] != '1')
	{
		if (data->map[data->y + 1][data->x] == 'E' && data->count_C == 0)
			finish_game(data, 'E');
		else if (data->map[data->y + 1][data->x] == 'B')
			finish_game(data, 'B');
		else if (data->map[data->y + 1][data->x] == '0' || data->map[data->y + 1][data->x] == 'C')
		{
			data->count_move += 1;
			if (data->map[data->y + 1][data->x] == 'C')
				data->count_C--;
			data->map[data->y][data->x] = '0';
			data->y += 1;
			data->map[data->y][data->x] = 'P';

			ft_printf("You Moved %d Times\n", data->count_move);
		}
	}
	data->direction = 'd';
}

void	move_right(t_list *data)
{
	if (data->map[data->y][data->x + 1] != '1')
	{
		if (data->map[data->y][data->x + 1] == 'E' && data->count_C == 0)
			finish_game(data, 'E');
		else if (data->map[data->y][data->x + 1] == 'B')
			finish_game(data, 'B');
		else if (data->map[data->y][data->x + 1] == '0' || data->map[data->y][data->x + 1] == 'C')
		{
			data->count_move += 1;
			if (data->map[data->y][data->x + 1] == 'C')
				data->count_C--;
			data->map[data->y][data->x] = '0';
			data->x += 1;
			data->map[data->y][data->x] = 'P';
			ft_printf("You Moved %d Times\n", data->count_move);
		}
	}
	data->direction = 'r';
}

void	move_left(t_list *data)
{
	if (data->map[data->y][data->x - 1] != '1')
	{
		if (data->map[data->y][data->x - 1] == 'E' && data->count_C == 0)
			finish_game(data, 'E');
		else if (data->map[data->y][data->x - 1] == 'B')
			finish_game(data, 'B');
		else if (data->map[data->y][data->x - 1] == '0' || data->map[data->y][data->x - 1] == 'C')
		{
			data->count_move += 1;
			if (data->map[data->y][data->x - 1] == 'C')
				data->count_C--;
			data->map[data->y][data->x] = '0';
			data->x -= 1;
			data->map[data->y][data->x] = 'P';
			ft_printf("You Moved %d Times\n", data->count_move);
		}
	}
	data->direction = 'l';
}

