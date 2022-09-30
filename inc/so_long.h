/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:03:45 by ademurge          #+#    #+#             */
/*   Updated: 2022/09/30 15:19:14 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

/*
** Libraries
*/

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

/*
** Define constants
*/

# define DESTROY_BUTTON 17
# define ESC 53
# define KEYPRESS 2
# define VALID_CHARACTERS "01EPC"

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

typedef struct s_data
{
	char	**map;
	int		length;
	int		width;
	void	*mlx;
	void	*win;
	t_img	img;
}	t_data;

/*
** so_long functions
*/

void	check(int ac, char **av, t_data *map);
int		close_win(t_data *map);
void	controls(t_data *map);
void	draw_line(t_coord start, t_coord end, t_data *map);
void	ft_error(char *s, char **map);
void	init_mlx(t_data *map);
int		keypress(int keycode, t_data *map);
void	pixel_put(t_img *img, int x, int y, int color);

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

#endif