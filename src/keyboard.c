/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:17:03 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/20 11:38:34 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_or_not(t_game *game, int x, int y)
{
	char	block;

	block = game->map[y][x];
	if (block == WALL || (block == EXIT && game->nb_items))
		return ;
	else if (block == BACKGROUND)
		move_player(game, x, y);
	else if (block == ITEM)
	{
		game->nb_items--;
		move_player(game, x, y);
	}
	else if (block == EXIT && !game->nb_items)
	{
		move_player(game, x, y);
	}
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_win(game);
	else if (keycode == W)
		move_or_not(game, game->player.pos.x, game->player.pos.y - 1);
	else if (keycode == S)
		move_or_not(game, game->player.pos.x, game->player.pos.y + 1);
	else if (keycode == A)
		move_or_not(game, game->player.pos.x - 1, game->player.pos.y);
	else if (keycode == D)
		move_or_not(game, game->player.pos.x + 1, game->player.pos.y);
	return (0);
}

void	controls(t_game *game)
{
	mlx_hook(game->win, KEYPRESS, 0, keypress, game);
	mlx_hook(game->win, DESTROY_BUTTON, 0, close_win, game);
}
