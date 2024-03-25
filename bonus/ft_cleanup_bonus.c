/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:24:33 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/25 02:23:20 by ahomari          ###   ########.fr       */
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
	mlx_destroy_window(data->mlx, data->mlx_win);
}

int	echap_exit(t_list *data)
{
	ft_printf("close!!\n");
	destroy_img(data);
	exit (0);
}

void	ft_cleanup(t_list *data)
{
	ft_free(data->map);
	free(data);
	destroy_img(data);
	exit(0);
}