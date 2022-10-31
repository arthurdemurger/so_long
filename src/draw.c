/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:19:42 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/31 18:44:37 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_block(t_game *game, int x, int y, char *file)
{
	game->map_sqr[y][x].img = mlx_xpm_file_to_image(game->mlx, file,
			&game->sqr_size, &game->sqr_size);
	mlx_put_image_to_window(game->mlx, game->win, game->map_sqr[y][x].img,
		x * 80, y * 80);
}

void	draw_sqr(t_game *game, char type, int x, int y)
{
	if (type == PLAYER)
		draw_block(game, x, y, PL_RIGHT_XPM);
	else if (game->map[y][x] == ITEM)
		draw_block(game, x, y, ITEM_XPM);
	else if (game->map[y][x] == EXIT)
		draw_block(game, x, y, CLOSED_EXIT_XPM);
	else if (game->map[y][x] == WALL)
		draw_block(game, x, y, WALL_XPM);
	else if (game->map[y][x] == GHOST)
		draw_block(game, x, y, GHOST_XPM);
	else
		draw_block(game, x, y, BACKGROUND_XPM);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			draw_sqr(game, game->map[i][j], j, i);
	}
}
