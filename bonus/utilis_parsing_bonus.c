/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_parsing_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:56:07 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/29 03:02:23 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

char	**read_map(t_list *data, char *file)
{
	int		fd;
	char	*tmp;
	char	*read;

	data->line_count = 0;
	fd = open(file, O_RDONLY);
	msg_error(fd, "Error\nFailed Open fd\n", data);
	data->str = ft_strdup("");
	read = get_next_line(fd);
	if (!read)
		msg_error(-1, "Error\nFailed Read\n", data);
	while (read)
	{
		data->line_count++;
		tmp = data->str;
		data->str = ft_strjoin(tmp, read);
		free(tmp);
		free(read);
		read = get_next_line(fd);
		if (!read || read[0] == '\n')
			break ;
	}
	close(fd);
	return (ft_split(data->str, '\n'));
}

int	check_map(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != c)
			return (1);
		i++;
	}
	return (0);
}

int	check_map1(char c1, char c2)
{
	if (c1 != '1' || c2 != '1')
		return (1);
	return (0);
}

int	check_map2(char **ptr, char *c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] != c[0] && ptr[i][j] != c[1] && ptr[i][j] != c[2]
				&& ptr[i][j] != c[3] && ptr[i][j] != c[4] && ptr[i][j] != c[5])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	valid_map1(t_list *data)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(data->ptr[0]);
	while (data->ptr[i] && i < data->line_count -1)
	{
		if (check_map1(data->ptr[i][0], data->ptr[i][len - 1]) == 1
			|| len != ft_strlen(data->ptr[i]))
			msg_error(-1, "Error\nInvalid Map\n", data);
		i++;
	}
	if (check_map2(data->ptr, "01CPEB") != 0)
		msg_error(-1, "Error\nInvalid Map\n", data);
	if (check_map(data->ptr[data->line_count - 1], '1') == 1
		|| check_map(data->ptr[0], '1') == 1
		|| data->ptr[data->line_count - 1][len] == '\n'
		|| len != ft_strlen(data->ptr[data->line_count - 1]))
		msg_error(-1, "Error\nInvalid Map\n", data);
}
