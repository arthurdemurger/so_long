/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:03:45 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/20 11:37:41 by ademurge         ###   ########.fr       */
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
# include <math.h>

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

/* XPM files */

# define PLAYER_XPM "xpm/steve.xpm"
# define ITEM_XPM "xpm/coffre.xpm"
# define EXIT_XPM "xpm/tnt.xpm"
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
	void	*img;
	char	*addr;
	int		bits_per_pix;
	int		line_length;
	int		endian;
}	t_img;

typedef struct player
{
	t_img	img;
	t_coord pos;
}	t_player;

typedef struct exit
{
	t_coord pos;
	int	status;
} t_exit;
typedef struct s_game
{
	t_player	player;
	t_img		**map_sqr;
	t_exit		exit;
	char		**map;
	int			length;
	int			width;
	int			nb_items;
	void		*win;
	void		*mlx;
	int			sqr_size;
}	t_game;

/*
** so_long functions
*/

void	check(int ac, char **av, t_game *game);
int		close_win(t_game *game);
void	controls(t_game *game);
void	draw_background(t_game *game);
void	draw_line(t_coord start, t_coord end, t_img img);
void	draw_map(t_game *game);
void	draw_sqr(t_game *game, char type, int x, int y);
void	free_map(char **map);
void	ft_error(char *s, t_game *game);
void	init_map_sqr(t_game *game);
void	init_mlx(t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
void	pixel_put(t_img *img, int x, int y, int color);
void	start_game(t_game *game);

/*
** libft functions
*/

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

#endif