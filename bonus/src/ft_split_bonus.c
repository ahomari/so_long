/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:41:13 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/29 03:03:19 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

static void	*free_split(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	ft_count_word(char const *str, char c)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] != c && check == 0)
		{
			check = 1;
			count++;
		}
		else if (str[i] == c)
			check = 0;
		i++;
	}
	return (count);
}

static char	**ft_print(char **ptr, char *s, char c)
{
	int		start;
	int		end;
	int		j;

	end = 0;
	j = 0;
	start = -1;
	while (end <= ft_strlen(s))
	{
		if (s[end] != c && start < 0)
			start = end;
		else if ((s[end] == c || end == ft_strlen(s)) && start >= 0)
		{
			ptr[j] = ft_substr(s, start, end - start);
			if (!(ptr[j]))
				return (free_split(ptr, j));
			start = -1;
			j++;
		}
		end++;
	}
	return (ptr);
}

char	**ft_split(char *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = ft_calloc((ft_count_word(s, c) + 1), sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr = ft_print(ptr, s, c);
	free(s);
	return (ptr);
}
