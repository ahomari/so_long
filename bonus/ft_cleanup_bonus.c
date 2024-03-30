/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:24:33 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/29 23:49:37 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	destroy_img(t_list *data)
{
	mlx_destroy_image(data->mlx, data->wall_img);
	mlx_destroy_image(data->mlx, data->floor);
	mlx_destroy_image(data->mlx, data->coins_img);
	mlx_destroy_image(data->mlx, data->door_close);
	mlx_destroy_image(data->mlx, data->door_open);
	mlx_destroy_image(data->mlx, data->player_img);
	mlx_destroy_image(data->mlx, data->player_right);
	mlx_destroy_image(data->mlx, data->player_left);
	mlx_destroy_image(data->mlx, data->player_top);
	mlx_destroy_image(data->mlx, data->player_down);
	mlx_destroy_image(data->mlx, data->monster[0]);
	mlx_destroy_image(data->mlx, data->monster[1]);
	mlx_destroy_image(data->mlx, data->monster[2]);
	mlx_destroy_image(data->mlx, data->monster[3]);
	mlx_destroy_image(data->mlx, data->monster[4]);
	mlx_destroy_window(data->mlx, data->mlx_win);
}

void	ft_cleanup(t_list *data)
{
	ft_free(data->map);
	ft_free(data->ptr);
	destroy_img(data);
	free(data->monster);
	free(data);
}

int	echap_exit(t_list *data)
{
	ft_printf("close!!\n");
	ft_cleanup(data);
	exit (0);
}
