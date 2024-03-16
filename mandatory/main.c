/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:37:42 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/16 12:00:20 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <string.h>

int map_len(t_list *data, char *str)
{
	data->map_len = 0;
	data->fd = open(str, O_RDONLY);
		msg_error(data->fd, "Failed Open !!");
	while (1)
	{
		data->str = get_next_line(data->fd);
		if (!data->str || data->str[0] == '\n')
			break ;
		data->map_len++;
	}
	close(data->fd);
	return (data->map_len);
}

char 	**read_map(t_list *data, char *str)
{
	data->map_len = map_len(data, str);
	data->fd = open(str, O_RDONLY);
		msg_error(data->fd, "Failed Open !!");
	data->ptr = (char **)malloc(data->map_len + 1 * sizeof(char *));
	if (!data->ptr)
		return (NULL);
	while (1)
	{
		data->str = get_next_line(data->fd);
		if (!data->str || data->str[0] == '\n')
			break ;
		data->ptr[data->i] = ft_strdup(data->str);
		data->i++;
	}
	data->ptr[data->i] = 0;
	// close(data->fd);
	return (data->ptr);
}

// char	**ft_realloc(char **ptr, char *str, size_t new_size)
// {
// 	char	**new_ptr;
// 	size_t	i;

// 	i = 0;
// 	new_ptr = (char **)malloc(sizeof(char *) * (new_size + 1));
// 	if (!new_ptr)
// 		return (NULL);
// 	while (ptr && ptr[i])
// 	{
// 		new_ptr[i] = ptr[i];
// 		ptr[i] = NULL;
// 		i++;
// 	}
// 	new_ptr[i] = str;
// 	i++;
// 	new_ptr[i] = NULL;
// 	free(ptr);
// 	return (new_ptr);
// }

int	check_map(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != c)
			return (1);
		i++;
	}
	return (0);
}

int check_map1(char c1, char c2)
{
	if (c1 != '1' || c2 != '1')
		return (1);
	return (0);
}

int check_map2(char *str, char c)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	position_player(char **ptr, int *x, int *y)
{
	t_list so;
	
	so.i = 0;
	while (ptr[so.i])
	{
		so.j = 0;
		while (ptr[so.i][so.j])
		{
			if (ptr[so.i][so.j] == 'P')
			{
				*x = so.j;
				*y = so.i;
			}
			so.j++;
		}
		so.i++;
	}
}

void	open_window(t_list *data)
{
	int i = 0;
	// int j = 0;
	data->img_path = "textures/wall.xpm";
	// while (data->map[i])
	// {

	// 	ft_printf("here ->%d\n", i);
	// 	// ft_printf("%s\n", data->map[i]);
	// 	i++;
	// }
	// ft_printf("here ->%d\n", data->map_len);
	// data->mlx = mlx_init();
	// if (!data->mlx)
	// {
	// 	ft_printf("mlx_init failed\n");
	// 	exit(1);
	// }
	while (i < data->map_len)
	{

		ft_printf("here ->%d\n", i);
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	// data->mlx_win = mlx_new_window(data->mlx, ft_strlen(data->map[0]) * 50, data->i * 50, "welcome to so_long!!");
	// data->img = mlx_xpm_file_to_image(data->mlx, data->img_path, &data->img_width, &data->img_height);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, i * 50, j * 50);
	// mlx_loop(data->mlx);
}

void	valid_map(t_list *data)
{
	
	data->j = 1;
	data->C_count = 0;
	data->E_count = 0;
	data->P_count = 0;
	
	if (!data->ptr)
		msg_error(-2, "Invalid Map1 !!");
	data->line_len = ft_strlen(data->ptr[0]);
	while (data->ptr[data->j] && data->j < data->i -1)
	{
		data->len = ft_strlen(data->ptr[data->j]) - 1;
		if (check_map1(data->ptr[data->j][0], data->ptr[data->j][data->len]) == 1)
			msg_error(-2, "Invalid Map2 !!");
		if (data->line_len != ft_strlen(data->ptr[data->j]))
			msg_error(-2, "Invalid Map !!");
		data->C_count += check_map2(data->ptr[data->j], 'C');
		data->E_count += check_map2(data->ptr[data->j], 'E');
		data->P_count += check_map2(data->ptr[data->j], 'P');
		data->j++;
	}
	if (check_map(data->ptr[0], '1') == 1 || check_map(data->ptr[data->i - 1], '1') == 1 || data->ptr[data->i - 1][data->len + 1] == '\n'
		|| data->C_count == 0 || data->E_count != 1 || data->P_count != 1 
			|| data->line_len != ft_strlen(data->ptr[data->i - 1]))
		msg_error(-2, "Invalid Map3 !!");
	position_player(data->ptr, &data->x, &data->y);
	flood_fill(data, data->x, data->y);
	// for (int i = 0; i < data->i; ++i)
	// 	printf("%s\n", data->ptr[i]);
	// for (int i = 0; i < data->i; ++i)
	// 	printf("%s\n", data->map[i]);
	if (data->C_count != 0 || data->E_count != 0)
		msg_error(-2, "Invalid Map4 !!");
	open_window(data);		
}


int main(int ac, char **av)
{
	t_list data;
	
	int i = 0;
	if (ac != 2)
		msg_error(-2, "Invalid Number of Argument");
	memset(&data, 0, sizeof(t_list));
	data.ptr = read_map(&data, av[1]);
	data.map = (char **)malloc(data.map_len + 1 * sizeof(char *));
	if (!data.map)
		return (1);
	while (data.ptr[i])
	{
		data.map[i] = ft_strdup(data.ptr[i]);
		i++;
	}
	data.map[i] = 0;
	valid_map(&data);
}
