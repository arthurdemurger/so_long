/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:17:03 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/20 15:38:51 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_or_not(t_game *game, int x, int y, char *direction)
{
	char	block;

	block = game->map[y][x];
	if (block == WALL || (block == EXIT && game->nb_items))
		return ;
	else if (block == BACKGROUND)
		move_player(game, x, y, direction);
	else if (block == ITEM)
	{
		game->nb_items--;
		move_player(game, x, y, direction);
	}
	else if (block == EXIT && !game->nb_items)
		move_player(game, x, y, direction);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_win(game);
	else if (keycode == W || keycode == KEY_UP)
		move_or_not(game, game->player_pos.x, game->player_pos.y - 1, MV_UP);
	else if (keycode == S|| keycode == KEY_DOWN)
		move_or_not(game, game->player_pos.x, game->player_pos.y + 1, MV_DOWN);
	else if (keycode == A || keycode == KEY_LEFT)
		move_or_not(game, game->player_pos.x - 1, game->player_pos.y, MV_LEFT);
	else if (keycode == D || keycode == KEY_RIGHT)
		move_or_not(game, game->player_pos.x + 1, game->player_pos.y, MV_RIGHT);
	return (0);
}

void	controls(t_game *game)
{
	mlx_hook(game->win, KEYPRESS, 0, keypress, game);
	mlx_hook(game->win, DESTROY_BUTTON, 0, close_win, game);
}
