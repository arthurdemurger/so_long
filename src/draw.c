/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:19:42 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/02 14:58:54 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_coord	find_pos(t_game *game)
{
	t_coord	pos;

	if ((game->width - 3) % 2 != 0)
		pos.x = (SIZE_SQR * (game->width - 3)) / 2;
	else
		pos.x = ((game->width - 3) / 2) * SIZE_SQR;
	if (game->height % 2 == 0)
		pos.y = (SIZE_SQR * (game->height - 1)) / 2;
	else
		pos.y = (game->height / 2) * SIZE_SQR;
	return (pos);
}

void	draw_end(t_game *game, int type_end)
{
	void	*end;
	int		height;
	int		width;

	height = SIZE_SQR;
	width = SIZE_SQR * 3;
	game->is_game_over = YES;
	mlx_clear_window(game->mlx, game->win);
	if (type_end == WIN)
	{
		end = mlx_xpm_file_to_image(game->mlx, WIN_XPM, &height, &width);
		mlx_put_image_to_window(game->mlx, game->win, end, find_pos(game).x,
			find_pos(game).y);
		mlx_destroy_image(game->mlx, end);
	}
	else if (type_end == LOSE)
	{
		end = mlx_xpm_file_to_image(game->mlx, LOSE_XPM, &height, &width);
		mlx_put_image_to_window(game->mlx, game->win, end, find_pos(game).x,
			find_pos(game).y);
		mlx_destroy_image(game->mlx, end);
	}
}

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
	mlx_string_put(game->mlx, game->win, 0, 0, 0xFFFFFF,
		"Total number of moves : 0");
}
