# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 22:28:31 by ademurge          #+#    #+#              #
#    Updated: 2022/11/09 01:09:16 by ademurge         ###   ########.fr        #
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

SRC			=	src/check.c \
				src/controls.c \
				src/draw.c \
				src/exit.c \
				src/game.c \
				src/ghost.c \
				src/init.c \
				src/main.c \
				src/utils.c

GNL			=	utils/gnl/get_next_line.c \
				utils/gnl/get_next_line_utils.c

LIBFT		=	utils/libft/ft_count.c \
				utils/libft/ft_dup_map.c \
				utils/libft/ft_find_pos.c \
				utils/libft/ft_itoa.c \
				utils/libft/ft_map_height.c \
				utils/libft/ft_putchar.c \
				utils/libft/ft_putendl_fd.c \
				utils/libft/ft_putnbr.c \
				utils/libft/ft_putstr_fd.c \
				utils/libft/ft_putstr.c \
				utils/libft/ft_split.c \
				utils/libft/ft_strchr.c \
				utils/libft/ft_strcmp.c \
				utils/libft/ft_strdup.c \
				utils/libft/ft_strjoin.c \
				utils/libft/ft_strlcat.c \
				utils/libft/ft_strlcpy.c \
				utils/libft/ft_strlen.c \
				utils/libft/ft_strstr.c \
				utils/libft/ft_substr.c \
				utils/libft/ft_swap.c

FT_PRINTF	=	utils/ft_printf/ft_conversion.c \
				utils/ft_printf/ft_print_memory.c \
				utils/ft_printf/ft_printf_utils.c \
				utils/ft_printf/ft_printf.c \
				utils/ft_printf/ft_putnbr_base.c

NAME		= so_long

CFLAGS		= -Wall -Wextra -Werror -L ./mlx -lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):
			@gcc ${CFLAGS} ${SRC} ${GNL} ${LIBFT} ${FT_PRINTF} -o ${NAME}
			@echo "$(GREEN)********** Compiled. $(RESET)"

clean:
			@rm -f ${OBJS}
			@echo "$(PURPLE)********** Objects removed. $(RESET)"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(LIGHTPURPLE)********** Executable removed. $(RESET)"

re:			fclean all

.PHONY:		all clean fclean re bonus


#gcc -Wall -Wextra -Werror -L ./mlx -lmlx -framework OpenGL -framework AppKit src/* gnl/* libft/* && < a.out cat | cat > fdf && chmod 777 fdf && rm a.out && ./fdf maps/map.ber