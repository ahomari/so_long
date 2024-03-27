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
void	sub_reload(t_list *data, int i, int j)
{
	if (data->map[i][j] == 'P')
	{	
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, j * 50, i * 50);
		if (data->direction == 'p')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, j * 50, i * 50);
		else if (data->direction == 'r')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_right, j * 50, i * 50);
		else if (data->direction == 'l')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_left, j * 50, i * 50);
		else if (data->direction == 'u')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_top, j * 50, i * 50);
		else if (data->direction == 'd')
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

// int		animation(t_list *data)
// {
// 	reload_map(data, 'b');    
//     usleep(100000);
//     data->index_enmy = (data->index_enmy % 5) + 1; 
// 	return (0);
// }
int render_car(t_list *data)
{
    int x;
    int y;

    x = 350;
    y = 350;
    mlx_clear_window(data->mlx, data->mlx_win);
    while(x < 450)
    {
        while(y < 450)
        {
        	mlx_put_image_to_window(data->mlx, data->mlx_win, data->monster[0], data->x, data->y);
        
        	y++;
        }
    y = 350;
    x++;
    }
    mlx_do_sync(data->mlx);
    return(1);
}

void	reload_map(t_list *data)
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
			else if (data->map[i][j] == 'B')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, j * 50, i * 50);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->monster[data->index_enmy], j * 50, i * 50);
			}
			else
				sub_reload(data, i, j);
		}
	}

	// mlx_string_put(data->mlx, data->mlx_win, 25, 25, 0xFFFFFF, data->nbr_move);
	ft_printf("%s\n", data->nbr_move);

}


void	**animation_init(t_list *data)
{
	data->monster = (void **)malloc(5 * sizeof(void *));
	if (!data->monster)
		msg_error(-2, "Error\n", data);
	data->monster[0] = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/frame_0.xpm", &data->img_width, &data->img_height);
	data->monster[1] = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/frame_1.xpm", &data->img_width, &data->img_height);
	data->monster[2] = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/frame_2.xpm", &data->img_width, &data->img_height);
	data->monster[3] = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/frame_3.xpm", &data->img_width, &data->img_height);
	data->monster[4] = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/frame_4.xpm", &data->img_width, &data->img_height);
	if (!data->monster[0] || !data->monster[1] || !data->monster[2] || !data->monster[3] || !data->monster[4])
		msg_error(-2, "Error\n", data);
	return (data->monster);
}
void	get_img(t_list *data)
{
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/wall.xpm", &data->img_width, &data->img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/floor.xpm", &data->img_width, &data->img_height);
	data->coins_img = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/coin.xpm", &data->img_width, &data->img_height);
	data->door_close = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/door_close.xpm", &data->img_width, &data->img_height);
	data->door_open = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/door_open.xpm", &data->img_width, &data->img_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/player.xpm", &data->img_width, &data->img_height);
	data->player_right = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/player_right.xpm", &data->img_width, &data->img_height);
	data->player_left = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/player_left.xpm", &data->img_width, &data->img_height);
	data->player_top = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/player_top.xpm", &data->img_width, &data->img_height);
	data->player_down = mlx_xpm_file_to_image(data->mlx, "bonus/textures_bonus/player_down.xpm", &data->img_width, &data->img_height);
	data->monster = animation_init(data);
	if (!data->wall_img || !data->floor || !data->coins_img || !data->door_close || !data->door_open 
		|| !data->player_img || !data->player_right || !data->player_left || !data->player_top || !data->player_down)
		msg_error(-2, "Error\n", data);
}