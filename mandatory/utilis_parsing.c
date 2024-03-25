/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:56:07 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/24 14:59:49 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char  	**read_map(t_list *data, char *file)
{
	int		fd;
	char	*tmp;
	char	*read;
	char	*str;
	
	data->line_count = 0;
	fd = open(file, O_RDONLY);
		msg_error(fd, "Failed Open !!\n");
	str = ft_strdup("");
	read = get_next_line(fd);
	if (!read)
		msg_error(-2, "Invalid Map\n");
	while (read)
	{
		data->line_count++;
		tmp = str;
		str = ft_strjoin(tmp, read);
		free(tmp);
		free(read);
		read = get_next_line(fd);
		if (!read || read[0] == '\n')
			break ;
	}
	close(fd);
	return (ft_split(str, '\n'));
}

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

void	valid_map1(char **ptr, int count_line, int	count_C, int count_E, int count_P)
{
	int i;
	int len;
	
	i = 1;
	len = ft_strlen(ptr[0]);
	while (ptr[i] && i < count_line -1)
	{
		if (check_map1(ptr[i][0], ptr[i][len - 1]) == 1)
			msg_error(-2, "Invalid Map2 !!");
		if (len != ft_strlen(ptr[i]))
			msg_error(-2, "Invalid Map !!");
		i++;
	}
	if (check_map(ptr[0], '1') == 1 || check_map(ptr[count_line - 1], '1') == 1 || ptr[count_line - 1][len] == '\n'
		|| count_C == 0 || count_E != 1 || count_P != 1 
			|| len != ft_strlen(ptr[count_line - 1]))
		msg_error(-2, "Invalid Map3 !!");
}

