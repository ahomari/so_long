FLAGS					= -Wall -Wextra -Werror
CC						= cc
RM						= rm -rf
NAME					= so_long
# NAME_BONUS				= 
HEAD					= include/so_long.h
# HEAD_BONUS				= include/.h 

# SRC_FUNC_B				= bonus/src_bonus/ft_atoi_bonus.c bonus/src_bonus/ft_calloc_bonus.c bonus/src_bonus/ft_free_bonus.c bonus/src_bonus/ft_isdigit_bonus.c \
# 							bonus/src_bonus/ft_lstadd_back_bonus.c bonus/src_bonus/ft_lstadd_front_bonus.c bonus/src_bonus/ft_lstlast_bonus.c bonus/src_bonus/ft_lstnew_bonus.c \
# 							bonus/src_bonus/ft_lstsize_bonus.c bonus/src_bonus/ft_putendl_fd_bonus.c bonus/src_bonus/ft_split_bonus.c bonus/src_bonus/ft_strdup_bonus.c bonus/src_bonus/ft_substr_bonus.c \
# 							bonus/gnl/ft_strjoinn_bonus.c bonus/gnl/get_next_line_bonus.c bonus/src_bonus/ft_strchr_bonus.c bonus/src_bonus/ft_strcpy_bonus.c bonus/src_bonus/ft_strcmp_bonus.c bonus/src_bonus/ft_lstclear_bonus.c
# F_BONUS_OBJ				= ${SRC_FUNC_B:.c=.o}

SRC_FUNC				= mandatory/ft_printf/ft_printf.c mandatory/ft_printf/utils.c mandatory/gnl/ft_strjoinn.c mandatory/gnl/get_next_line.c mandatory/src/ft_strchr.c mandatory/src/ft_strcpy.c mandatory/src/ft_strdup.c mandatory/src/ft_strlen.c \
							mandatory/src/ft_calloc.c mandatory/src/msg_error.c mandatory/src/ft_strcmp.c mandatory/src/flood_fill.c
F_OBJ					= ${SRC_FUNC:.c=.o}

# SRC_BUNUS				= bonus/checker_bonus.c bonus/msg_error_bonus.c bonus/operations_ab_bonus.c bonus/operations_bonus.c bonus/get_checker_bonus.c bonus/main_bonus.c
# S_BONUS_OBJ				= ${SRC_BUNUS:.c=.o}

SRC_MAN					= mandatory/main.c
S_OBJ					= ${SRC_MAN:.c=.o}

# %bonus.o: %bonus.c		${HEAD_BONUS}
# 						${CC} ${FLAGS} -c $< -o $@

%.o: %.c				${HEAD}
						${CC} ${FLAGS} -Imlx -c $< -o $@


${NAME}:				${F_OBJ} ${S_OBJ} include/so_long.h
						@${CC} ${F_OBJ} ${S_OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME} -fsanitize=address
						@echo "${GREEN}${NAME} Created!${DEFAULT}"

# bonus  :				${F_BONUS_OBJ} ${S_BONUS_OBJ}
# 						@${CC} ${F_BONUS_OBJ} ${S_BONUS_OBJ} -o ${NAME_BONUS}
# 						@echo "${GREEN}${NAME_BONUS} Created!${DEFAULT}"

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