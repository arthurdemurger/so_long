/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:03:45 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/31 11:42:39 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

/*
** Libraries
*/

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

/*
** Define constants
*/

/* Keyboard */

# define DESTROY_BUTTON 17
# define ESC 53
# define KEYPRESS 2
# define W 13
# define A 0
# define S 1
# define D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

/* Sizing */

# define BUFFER_SIZE 42
# define SIZE_SQR 64

/* Characters */

# define VALID_CHARACTERS "01EPC"
# define FOUND 2
# define OPEN 1
# define CLOSED 0
# define PLAYER 'P'
# define WALL '1'
# define EXIT 'E'
# define ITEM 'C'
# define BACKGROUND '0'
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define MV_UP "up   "
# define MV_DOWN "down "
# define MV_RIGHT "right"
# define MV_LEFT "left "
# define YES 1
# define NO 0

/* XPM files */

# define PLAYER_XPM "xpm/player.xpm"
# define ITEM_XPM "xpm/item.xpm"
# define OPEN_EXIT_XPM "xpm/open_exit.xpm"
# define CLOSED_EXIT_XPM "xpm/closed_exit.xpm"
# define WALL_XPM "xpm/wall.xpm"
# define BACKGROUND_XPM "xpm/background.xpm"

/*
** Structures
*/

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_img
{
	char	*addr;
	int		bits_per_pix;
	int		endian;
	void	*img;
	int		line_length;
}	t_img;

typedef struct s_game
{
	t_coord		exit_pos;
	int			exit_status;
	int			is_mlx;
	int			length;
	t_img		**map_sqr;
	char		**map;
	void		*mlx;
	int			nb_items;
	int			nb_move;
	t_coord		player_pos;
	int			sqr_size;
	int			width;
	void		*win;
}	t_game;

/*
** so_long functions
*/

void	check(int ac, char **av, t_game *game);
void	controls(t_game *game);
void	draw_background(t_game *game);
void	draw_line(t_coord start, t_coord end, t_img img);
void	draw_map(t_game *game);
void	draw_sqr(t_game *game, char type, int x, int y);
int		end_game(t_game *game, int type_exit);
void	ft_error(char *s, t_game *game);
void	init_map_sqr(t_game *game);
void	init_mlx(t_game *game);
void	move_player(t_game *game, int new_x, int new_y, char *direction);
void	pixel_put(t_img *img, int x, int y, int color);
void	replace_sqr(t_game *game, int x, int y, char *xpm_file);
void	start_game(t_game *game);

/*
** libft functions
*/

t_coord	ft_find_pos(t_game *game, char block);
int		ft_map_width(char **map);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *s);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlcpy(char *dest, const char *src, int size);
int		ft_strlen(char *str);
char	*ft_strstr(char *big, char *little);
char	*ft_substr(char *s, int start, int len);
void	ft_swap(int *x, int *y);

/*
** gnl functions
*/

char	*get_next_line(int fd);
int		is_line_break(char *str);
int		ft_strlen(char *s);
char	*ft_strdup(char *src);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char const *s, int start, int len);

/*
** ft_printf
*/

/* constants */

# define DECIMAL "0123456789"
# define UP_HEXADECIMAL "0123456789ABCDEF"
# define LOW_HEXADECIMAL "0123456789abcdef"
# define SIGNED 1
# define UNSIGNED 0

/* functions */

int		ft_printf(const char *str, ...);
void	printf_putchar(char c, int *count);
void	printf_putstr(char *str, int *count);
void	printf_putnbr(int n, int *count);
void	printf_putnbr_base(int nbr, int sign, char *base_set, int *count);
int		is_conversion(char c);
void	do_conversion(char c, va_list args, int *count);
void	ft_print_address(void *add, int *count);

#endif