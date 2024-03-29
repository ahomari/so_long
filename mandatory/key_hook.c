/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:49:05 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/28 12:36:59 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_list *data)
{
	if (keycode == 126 || keycode == 13)
		move_up(data);
	else if (keycode == 125 || keycode == 1)
		move_down(data);
	else if (keycode == 124 || keycode == 2)
		move_right(data);
	else if (keycode == 123 || keycode == 0)
		move_left(data);
	else if (keycode == 53)
		echap_exit(data);
	reload_map(data);
	return (0);
}

// 126  13 up; y - 1
// 125  1 down; y + 1
// 124 2 right  x +1 ;
// 123  0 left; x - 1