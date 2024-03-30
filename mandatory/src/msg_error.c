/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:23:21 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/29 23:06:25 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_print_msg(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write (2, &msg[i], 1);
		i++;
	}
	exit(1);
}

void	msg_error(int num, char *msg, t_list *data)
{
	if (num == -1)
	{
		if (data->str != NULL)
			free(data->str);
		if (data->ptr != NULL)
			ft_free(data->ptr);
		if (data->map != NULL)
			ft_free(data->map);
		free(data);
		ft_print_msg(msg);
	}
	else if (num == -2)
	{
		ft_cleanup(data);
		ft_print_msg(msg);
	}
	else if (num == -3)
		ft_print_msg(msg);
}
