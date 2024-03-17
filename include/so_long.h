/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:50:29 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/17 15:29:55 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  10
# endif

typedef struct s_list
{
	int		x;
	int		y;
	char	*read;
	char	*str;
	char	*tmp;
	char	**ptr;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*wall_img;
	void	*coins_img;
	void	*exit_img;
	void	*exit_open_img;
	void	*player_img;
	int		img_width;
	int		img_height;
	int		i;
	int		img_i;
	int		img_j;
	int		len;
	int		line_count;
	int		line_len;
	int		C_count;
	int		E_count;
	int		P_count;
	int		fd;
	int 	map_len;
	
	
}					t_list;

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <mlx.h>
# include <libc.h>


char	*ft_strjoinn(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *count);
void	ft_putnbr_long(long nbr, int *count);
void	ft_putstr(char *str, int *count);
int		ft_strchr(char *s, char c);
char	*ft_strcpy(char *dst, char const *src, size_t len);
char	*ft_strdup(char *s1);
int		ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
void	msg_error(int num, char *msg);
int		ft_strcmp(const char *s1, const char *s2);
void	flood_fill(t_list *data, int pos_x, int pos_y);
int		check_map(char *str, char c);
int		check_map1(char c1, char c2);
int		check_map2(char *str, char c);
void	position_player(char **ptr, int *x, int *y);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
int		key_hook(int keycode, t_list *data);
void	reload_map(t_list *data);
void	*ft_free(char **strs);
#endif