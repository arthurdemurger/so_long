/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:38:20 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/10 13:24:06 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

char	*find_gh_xpm(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->ghost.cur_xpm == i)
		{
			if (i == 3)
				game->ghost.cur_xpm = 0;
			else
				game->ghost.cur_xpm = ++i;
		}
	}
	return (game->ghost.xpm[game->ghost.cur_xpm]);
}

void	move_ghost(t_game *game)
{
	int	x;
	int	y;

	x = ft_find_pos(game, GHOST).x;
	y = ft_find_pos(game, GHOST).y;
	if (game->ghost.dir == RIGHT)
	{
		if (game->map[y][x + 1] == BACKGROUND)
			replace_sqr(game, ft_find_pos(game, GHOST), coord_to_pos(x + 1, y),
				find_gh_xpm(game));
		else if (game->map[y][x + 1] == PLAYER)
			draw_end(game, LOSE);
		else
			game->ghost.dir = LEFT;
	}
	else if (game->ghost.dir == LEFT)
	{
		if (game->map[y][x - 1] == BACKGROUND)
			replace_sqr(game, ft_find_pos(game, GHOST), coord_to_pos(x - 1, y),
				find_gh_xpm(game));
		else if (game->map[y][x - 1] == PLAYER)
			draw_end(game, LOSE);
		else
			game->ghost.dir = RIGHT;
	}
}

int	sprites(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = ft_find_pos(game, GHOST).x;
	y = ft_find_pos(game, GHOST).y;
	if (game->status == PLAYING)
	{
		mlx_destroy_image(game->mlx, game->map_sqr[y][x]);
		put_img(game, x, y, find_gh_xpm(game));
		move_ghost(game);
	}
	i = -1;
	while (++i < 50000000)
		;
	return (0);
}
