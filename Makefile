# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 22:28:31 by ademurge          #+#    #+#              #
#    Updated: 2022/10/18 15:11:00 by ademurge         ###   ########.fr        #
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
				src/draw.c \
				src/error.c \
				src/game.c \
				src/init.c \
				src/keyboard.c \
				src/main.c

GNL			=	gnl/get_next_line.c \
				gnl/get_next_line_utils.c

LIBFT		=	libft/ft_map_width.c \
				libft/ft_putendl_fd.c \
				libft/ft_putstr_fd.c \
				libft/ft_putstr.c \
				libft/ft_split.c \
				libft/ft_strchr.c \
				libft/ft_strdup.c \
				libft/ft_strjoin.c \
				libft/ft_strlcpy.c \
				libft/ft_strlen.c \
				libft/ft_strstr.c \
				libft/ft_substr.c \
				libft/ft_swap.c

NAME		= so_long

CFLAGS		= -Wall -Wextra -Werror -L ./mlx -lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):
			@gcc ${CFLAGS} ${SRC} ${GNL} ${LIBFT} -o ${NAME}
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