# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 22:28:31 by ademurge          #+#    #+#              #
#    Updated: 2022/11/10 13:57:04 by ademurge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

SRC			=			mandatory/src/check.c \
						mandatory/src/controls.c \
						mandatory/src/draw.c \
						mandatory/src/exit.c \
						mandatory/src/game.c \
						mandatory/src/init.c \
						mandatory/src/main.c \
						mandatory/src/utils.c

GNL			=			mandatory/utils/gnl/get_next_line.c \
						mandatory/utils/gnl/get_next_line_utils.c

LIBFT		=			mandatory/utils/libft/ft_count.c \
						mandatory/utils/libft/ft_dup_map.c \
						mandatory/utils/libft/ft_find_pos.c \
						mandatory/utils/libft/ft_itoa.c \
						mandatory/utils/libft/ft_map_height.c \
						mandatory/utils/libft/ft_putchar.c \
						mandatory/utils/libft/ft_putendl_fd.c \
						mandatory/utils/libft/ft_putnbr.c \
						mandatory/utils/libft/ft_putstr_fd.c \
						mandatory/utils/libft/ft_putstr.c \
						mandatory/utils/libft/ft_split.c \
						mandatory/utils/libft/ft_strchr.c \
						mandatory/utils/libft/ft_strcmp.c \
						mandatory/utils/libft/ft_strdup.c \
						mandatory/utils/libft/ft_strjoin.c \
						mandatory/utils/libft/ft_strlcat.c \
						mandatory/utils/libft/ft_strlcpy.c \
						mandatory/utils/libft/ft_strlen.c \
						mandatory/utils/libft/ft_strstr.c \
						mandatory/utils/libft/ft_substr.c \
						mandatory/utils/libft/ft_swap.c

FT_PRINTF	=			mandatory/utils/ft_printf/ft_conversion.c \
						mandatory/utils/ft_printf/ft_print_memory.c \
						mandatory/utils/ft_printf/ft_printf_utils.c \
						mandatory/utils/ft_printf/ft_printf.c \
						mandatory/utils/ft_printf/ft_putnbr_base.c

BONUS_SRC			=	bonus/src/check_bonus.c \
						bonus/src/controls_bonus.c \
						bonus/src/draw_bonus.c \
						bonus/src/exit_bonus.c \
						bonus/src/game_bonus.c \
						bonus/src/ghost_bonus.c \
						bonus/src/init_bonus.c \
						bonus/src/main_bonus.c \
						bonus/src/utils_bonus.c

BONUS_GNL	=			bonus/utils/gnl/get_next_line_bonus.c \
						bonus/utils/gnl/get_next_line_utils_bonus.c

BONUS_LIBFT	=			bonus/utils/libft/ft_count_bonus.c \
						bonus/utils/libft/ft_dup_map_bonus.c \
						bonus/utils/libft/ft_find_pos_bonus.c \
						bonus/utils/libft/ft_itoa_bonus.c \
						bonus/utils/libft/ft_map_height_bonus.c \
						bonus/utils/libft/ft_putchar_bonus.c \
						bonus/utils/libft/ft_putendl_fd_bonus.c \
						bonus/utils/libft/ft_putnbr_bonus.c \
						bonus/utils/libft/ft_putstr_fd_bonus.c \
						bonus/utils/libft/ft_putstr_bonus.c \
						bonus/utils/libft/ft_split_bonus.c \
						bonus/utils/libft/ft_strchr_bonus.c \
						bonus/utils/libft/ft_strcmp_bonus.c \
						bonus/utils/libft/ft_strdup_bonus.c \
						bonus/utils/libft/ft_strjoin_bonus.c \
						bonus/utils/libft/ft_strlcat_bonus.c \
						bonus/utils/libft/ft_strlcpy_bonus.c \
						bonus/utils/libft/ft_strlen_bonus.c \
						bonus/utils/libft/ft_strstr_bonus.c \
						bonus/utils/libft/ft_substr_bonus.c \
						bonus/utils/libft/ft_swap_bonus.c

BONUS_FT_PRINTF	=		bonus/utils/ft_printf/ft_conversion_bonus.c \
						bonus/utils/ft_printf/ft_print_memory_bonus.c \
						bonus/utils/ft_printf/ft_printf_utils_bonus.c \
						bonus/utils/ft_printf/ft_printf_bonus.c \
						bonus/utils/ft_printf/ft_putnbr_base_bonus.c

NAME		= so_long

CFLAGS		= -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):
			@gcc ${CFLAGS} ${SRC} ${GNL} ${LIBFT} ${FT_PRINTF} -o ${NAME}
			@echo "$(GREEN)********** Compiled. $(RESET)"

bonus:
			@gcc ${CFLAGS} ${BONUS_SRC} ${BONUS_GNL} ${BONUS_LIBFT} ${BONUS_FT_PRINTF} -o bonus_slg
			@echo "$(YELLOW)********** Bonus compiled. $(RESET)"

clean:
			@rm -f ${OBJS}
			@echo "$(PURPLE)********** Objects removed. $(RESET)"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(LIGHTPURPLE)********** Executable removed. $(RESET)"

re:			fclean all

.PHONY:		all clean fclean re bonus

#gcc -Wall -Wextra -Werror -L ./mlx -lmlx -framework OpenGL -framework AppKit src/* gnl/* libft/* && < a.out cat | cat > fdf && chmod 777 fdf && rm a.out && ./fdf maps/map.ber