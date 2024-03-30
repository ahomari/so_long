/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:31:20 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/30 01:31:48 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**read_map(t_list *data, char *file)
{
	int		fd;
	char	*tmp;
	char	*read;

	data->line_count = 0;
	fd = open(file, O_RDONLY);
	msg_error(fd, "Error\nFailed Open fd\n", data);
	read = get_next_line(fd);
	if (!read || read[0] == '\n')
		msg_error(-1, "Error\nInvalid Map\n", data);
	while (1)
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
	if (ft_check_newline(data->str) == 1)
		msg_error(-1, "Error\nInvalid Map\n", data);
	close(fd);
	return (ft_split(data->str, '\n'));
}
