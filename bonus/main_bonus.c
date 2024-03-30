/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:32:30 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/30 01:25:36 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	return_size(char **env)
{
	int	index;

	index = 0;
	while (env[index])
		index++;
	return (index);
}

void	open_window(t_list *data, char *file)
{
	data->str = ft_strdup("");
	data->map = read_map(data, file);
	if (!data->map)
		msg_error(-1, "Error\ndata->map = NULL\n", data);
	free(data->str);
	data->str = NULL;
	data->count_c = count_elm(data->map, 'C');
	data->count_e = count_elm(data->map, 'E');
	data->count_p = count_elm(data->map, 'P');
	data->count_b = count_elm(data->map, 'B');
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, ft_strlen(data->map[0]) * 50,
			return_size(data->map) * 50, "welcome to so_long_bonus");
	data->direction = 'p';
	get_img(data);
	reload_map(data);
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, echap_exit, data);
}

void	parsing(t_list *data, char *file)
{
	data->str = ft_strdup("");
	data->ptr = read_map(data, file);
	if (!data->ptr)
		msg_error(-1, "Error\ndata->ptr = NULL\n", data);
	free(data->str);
	data->str = NULL;
	data->count_c = count_elm(data->ptr, 'C');
	data->count_e = count_elm(data->ptr, 'E');
	data->count_p = count_elm(data->ptr, 'P');
	data->count_b = count_elm(data->ptr, 'B');
	if (data->count_c == 0 || data->count_e != 1
		|| data->count_p != 1 || data->count_b == 0)
		msg_error(-1, "Error\nInvalid Map1\n", data);
	valid_map1(data);
	position_player(data);
	flood_fill(data, data->x, data->y);
	if (data->count_c != 0 || data->count_e != 0)
		msg_error(-1, "Error\nInvalid Map2\n", data);
	open_window(data, file);
}

int	main(int ac, char **av)
{
	t_list	*data;

	data = malloc(sizeof(t_list));
	if (!data)
		msg_error(-3, "Error\n", data);
	ft_memset(data, 0, sizeof(t_list));
	if (ac != 2)
		msg_error(-1, "Invalid Number of Argument\n", data);
	data->len_file = ft_strlen(av[1]) - 4;
	if (ft_strcmp(av[1] + data->len_file, ".ber") != 0)
		msg_error(-1, "Error\nInvalid Map3\n", data);
	parsing(data, av[1]);
	mlx_loop(data->mlx);
}
