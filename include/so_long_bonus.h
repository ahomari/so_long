/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:32:50 by ahomari           #+#    #+#             */
/*   Updated: 2024/03/25 15:44:15 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_list
{
	int		count_C;
	int		count_E;
	int		count_P;
	int		count_I;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		line_count;
	int		count_move;
	char	**map;
	void	*floor;
	void	*door_open;
	void	*mlx;
	void	*mlx_win;
	void	*wall_img;
	void	*coins_img;
	void	*player_img;
	void	*door_close;
	void	*player_right;
	void	*player_left;
	void	*player_top;
	void	*player_down;
}					t_list;



char	*ft_strjoinn(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *count);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putnbr_long(long nbr, int *count);
void	ft_putstr(char *str, int *count);
int		ft_strchr(char *s, char c);
char	*ft_strcpy(char *dst, char const *src, size_t len);
char	*ft_strdup(char *s1);
int		ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
void	msg_error(int num, char *msg);
int		ft_strcmp(const char *s1, const char *s2);
void	flood_fill(char **ptr, int pos_x, int pos_y, t_list *data);
int		check_map(char *str, char c);
void	position_player(char **ptr, int *x, int *y);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
void	*ft_free(char **strs);
int		count_CEP(char **ptr, char c);
char  	**read_map(t_list *data, char *file);
int		key_hook(int keycode, t_list *data);
void	reload_map(t_list *data, char c);
void	move_left(t_list *data);
void	move_right(t_list *data);
void	move_down(t_list *data);
void	move_up(t_list *data);
void	finish_game(t_list *data);
int		check_map1(char c1, char c2);
void	get_img(t_list *data);
int		echap_exit(t_list *data);
void	valid_map1(char **ptr, t_list *data);
void	destroy_img(t_list *data);
void	ft_cleanup(t_list *data);

#endif