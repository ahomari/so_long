/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:37:42 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/17 15:32:41 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_CEP(char **ptr, t_list *data)
{
	int i;

	i = 1;
	while (ptr[i] && i < data->line_count -1)
	{
		data->C_count += check_map2(ptr[i], 'C');
		data->E_count += check_map2(ptr[i], 'E');
		data->P_count += check_map2(ptr[i], 'P');
		i++;
	}
}

void 	read_map(t_list *data, char *file)
{
	data->fd = open(file, O_RDONLY);
		msg_error(data->fd, "Failed Open !!");
	data->str = ft_strdup("");
	while (1)
	{
		data->read = get_next_line(data->fd);
		if (!data->read || data->read[0] == '\n')
			break ;
		data->line_count++;
		data->tmp = data->str;
		data->str = ft_strjoin(data->tmp, data->read);
		free(data->tmp);
		free(data->read);
	}
	close(data->fd);
}

int return_size(char **env)
{
	int index = 0;

	while (env[index])
		index++ ;
	return index ;
}

void	reload_map(t_list *data)
{
	data->img_i = 0;
	while (data->map[data->img_i])
	{
		data->img_j = 0;
		while (data->map[data->img_i][data->img_j])
		{
			if (data->map[data->img_i][data->img_j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_img, data->img_j * 50, data->img_i * 50);
			else if (data->map[data->img_i][data->img_j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->coins_img, data->img_j * 50, data->img_i * 50);
			else if (data->map[data->img_i][data->img_j] == 'E')
			{
				if (data->C_count != 0)
					mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_img, data->img_j * 50, data->img_i * 50);
				else
					mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_open_img, data->img_j * 50, data->img_i * 50);
			}
			else if (data->map[data->img_i][data->img_j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, data->img_j * 50, data->img_i * 50);
			data->img_j++;
		}
		data->img_i++;
	}
	mlx_key_hook(data->mlx_win, key_hook, data);
}

void	open_window(t_list *data, char *file)
{
	data->mlx = mlx_init();
	read_map(data, file);
	data->map = ft_split(data->str, '\n');
	count_CEP(data->map, data);
	data->mlx_win = mlx_new_window(data->mlx, ft_strlen(data->map[0]) * 50, return_size(data->map) * 50, "welcome to so_long!!");
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &data->img_width, &data->img_height);
	data->coins_img = mlx_xpm_file_to_image(data->mlx, "textures/rr.xpm", &data->img_width, &data->img_height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm", &data->img_width, &data->img_height);
	data->exit_open_img = mlx_xpm_file_to_image(data->mlx, "textures/open_exit.xpm", &data->img_width, &data->img_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm", &data->img_width, &data->img_height);
	reload_map(data);
}

void	valid_map(t_list *data, char *file)
{
	data->i = 1;
	read_map(data, file);
	data->ptr = ft_split(data->str, '\n');
	count_CEP(data->ptr, data);
	if (!data->ptr)
		msg_error(-2, "Invalid Map1 !!");
	data->line_len = ft_strlen(data->ptr[0]);
	while (data->ptr[data->i] && data->i < data->line_count -1)
	{
		data->len = ft_strlen(data->ptr[data->i]) - 1;
		if (check_map1(data->ptr[data->i][0], data->ptr[data->i][data->len]) == 1)
			msg_error(-2, "Invalid Map2 !!");
		if (data->line_len != ft_strlen(data->ptr[data->i]))
			msg_error(-2, "Invalid Map !!");
		data->i++;
	}
	if (check_map(data->ptr[0], '1') == 1 || check_map(data->ptr[data->line_count - 1], '1') == 1 || data->ptr[data->line_count - 1][data->len + 1] == '\n'
		|| data->C_count == 0 || data->E_count != 1 || data->P_count != 1 
			|| data->line_len != ft_strlen(data->ptr[data->line_count - 1]))
		msg_error(-2, "Invalid Map3 !!");
	position_player(data->ptr, &data->x, &data->y);
	flood_fill(data, data->x, data->y);
	if (data->C_count != 0 || data->E_count != 0)
		msg_error(-2, "Invalid Map4 !!");
	ft_free(data->ptr);
}

void	f()
{
	system("leaks so_long");
}

int main(int ac, char **av)
{
	t_list data;
	atexit(f);
	memset(&data, 0, sizeof(data));
	if (ac != 2)
		msg_error(-2, "Invalid Number of Argument");
	valid_map(&data, av[1]);
	open_window(&data, av[1]);
	mlx_loop(&data.mlx);
	// move_player(&data);
	
	// data.map = (char **)malloc(data.map_len + 1 * sizeof(char *));
	// if (!data.map)
	// 	return (1);
	// while (data.ptr[i])
	// {
	// 	data.map[i] = ft_strdup(data.ptr[i]);
	// 	i++;
	// }
	// data.map[i] = 0;
}
