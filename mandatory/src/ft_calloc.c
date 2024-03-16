/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:19:21 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/13 23:20:05 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	int		len;
	char	*ptr;

	ptr = (void *)(malloc(count * size));
	if (!ptr)
		return (NULL);
	len = count * size;
	i = 0;
	while (len--)
		ptr[i++] = 0;
	return (ptr);
}
