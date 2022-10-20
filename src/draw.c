/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:19:42 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/20 11:35:37 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	draw_block(t_game *game, int x, int y, char *file)
{
	int	size;

	size = SIZE_SQR;
	game->map_sqr[y][x].img = mlx_xpm_file_to_image(game->mlx, file, &size,
			&size);
	mlx_put_image_to_window(game->mlx, game->win, game->map_sqr[y][x].img,
		x * 64, y * 64);
}

void	draw_sqr(t_game *game, char type, int x, int y)
{
	if (type == PLAYER)
	{
		draw_block(game, x, y, PLAYER_XPM);
		game->player.img = game->map_sqr[y][x];
	}
	else if (game->map[y][x] == ITEM)
		draw_block(game, x, y, ITEM_XPM);
	else if (game->map[y][x] == EXIT)
		draw_block(game, x, y, EXIT_XPM);
	else if (game->map[y][x] == WALL)
		draw_block(game, x, y, WALL_XPM);
	else
		draw_block(game, x, y, BACKGROUND_XPM);
}
