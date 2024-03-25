/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:32:30 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/25 02:23:29 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int return_size(char **env)
{
	int index = 0;

	while (env[index])
		index++ ;
	return index ;
}

void	open_window(t_list *data, char *file)
{
	data->map = read_map(data, file);
	if (!data->map)
		msg_error(-2, "error\n");
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, ft_strlen(data->map[0]) * 50, return_size(data->map) * 50, "welcome to so_long!!");
	get_img(data);
	reload_map(data, 'p');
}

// void	f(){system("leaks so_long");}

void	parsing(t_list *data, char *file)
{
	char	**ptr;
	int		count_C;
	int		count_E;
	int		count_P;
	
	ptr = read_map(data, file);
	if (!ptr)
		msg_error(-2, "Error !!");
	count_C = count_CEP(ptr, 'C');
	count_E = count_CEP(ptr, 'E');
	count_P = count_CEP(ptr, 'P');
	data->count_C = count_C;
	valid_map1(ptr, data->line_count, count_C, count_E, count_P);
	position_player(ptr, &data->x, &data->y);
	flood_fill(ptr, data->x, data->y, &count_C, &count_E);
	if (count_C != 0 || count_E != 0)
		msg_error(-2, "Invalid Map4 !!");
	ft_free(ptr);
	open_window(data, file);
}

int	main(int ac, char **av)
{
	t_list *data;
	
	data = malloc(sizeof(t_list));
	ft_memset(data, 0, sizeof(t_list));
	if (ac != 2)
		msg_error(-2, "Invalid Number of Argument");
	parsing(data, av[1]);
	mlx_loop(data->mlx);
}