FLAGS					= -Wall -Wextra -Werror
CC						= cc
RM						= rm -rf
NAME					= so_long
NAME_BONUS				= so_long_bonus
HEAD					= include/so_long.h
HEAD_BONUS				= include/so_long_bonus.h 

SRC_FUNC_B				= bonus/ft_printf/ft_printf_bonus.c bonus/ft_printf/utils_bonus.c bonus/gnl/ft_strjoinn_bonus.c bonus/gnl/get_next_line_bonus.c bonus/src/flood_fill_bonus.c bonus/src/ft_calloc_bonus.c bonus/src/ft_free_bonus.c bonus/src/ft_memset_bonus.c \
							bonus/src/ft_split_bonus.c bonus/src/ft_strchr_bonus.c bonus/src/ft_strcmp_bonus.c bonus/src/ft_strcpy_bonus.c bonus/src/ft_strdup_bonus.c bonus/src/ft_strjoin_bonus.c bonus/src/ft_strlen_bonus.c bonus/src/ft_substr_bonus.c bonus/src/msg_error_bonus.c
F_BONUS_OBJ				= ${SRC_FUNC_B:.c=.o} 

SRC_FUNC				= mandatory/ft_printf/ft_printf.c mandatory/ft_printf/utils.c mandatory/gnl/ft_strjoinn.c mandatory/gnl/get_next_line.c mandatory/src/ft_strchr.c mandatory/src/ft_strcpy.c mandatory/src/ft_strdup.c mandatory/src/ft_strlen.c \
							mandatory/src/ft_calloc.c mandatory/src/msg_error.c mandatory/src/ft_strcmp.c mandatory/src/flood_fill.c mandatory/src/ft_strjoin.c mandatory/src/ft_split.c mandatory/src/ft_substr.c mandatory/src/ft_free.c \
							mandatory/src/ft_memset.c
F_OBJ					= ${SRC_FUNC:.c=.o}

SRC_BUNUS				= bonus/ft_cleanup_bonus.c bonus/key_hook_bonus.c bonus/main_bonus.c bonus/move_player_bonus.c bonus/utilis_game_bonus.c bonus/utilis_parsing_bonus.c
S_BONUS_OBJ				= ${SRC_BUNUS:.c=.o}

SRC_MAN					= mandatory/main.c  mandatory/key_hook.c mandatory/move_player.c mandatory/utilis_game.c mandatory/utilis_parsing.c mandatory/ft_cleanup.c
S_OBJ					= ${SRC_MAN:.c=.o}

%bonus.o: %bonus.c		${HEAD_BONUS}
						${CC} ${FLAGS} -c $< -o $@

%.o: %.c				${HEAD}
						${CC} ${FLAGS} -Imlx -c $< -o $@


${NAME}:				${F_OBJ} ${S_OBJ} include/so_long.h
						@${CC} ${F_OBJ} ${S_OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME}
						@echo "${GREEN}${NAME} Created!${DEFAULT}"

bonus  :				${F_BONUS_OBJ} ${S_BONUS_OBJ} include/so_long_bonus.h
						@${CC} ${F_BONUS_OBJ} ${S_BONUS_OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME_BONUS}
						@echo "${GREEN}${NAME_BONUS} Created!${DEFAULT}"

all:					${NAME}


clean:
						@${RM} ${F_OBJ}
						@${RM} ${S_OBJ}
						@${RM} ${F_BONUS_OBJ}
						@${RM} ${S_BONUS_OBJ}
						@echo "${YELLOW}Object Files deleted!${DEFAULT}"

fclean:					clean
						@${RM} ${NAME} ${NAME_BONUS}
						@echo "${RED}All Deleted!${DEFAULT}"

re: 					fclean all

.PHONY: 				fclean all re  clean

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m