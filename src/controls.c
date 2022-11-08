/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:17:03 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/08 15:21:56 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		end_game(game, EXIT_SUCCESS);
	else if (game->check.is_game_over == YES)
		return (0);
	else if (keycode == W || keycode == KEY_UP)
		move_or_not(game, game->player_pos.x, game->player_pos.y - 1, MV_UP);
	else if (keycode == S || keycode == KEY_DOWN)
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
	mlx_hook(game->win, DESTROY_BUTTON, 0, end_game, game);
	mlx_put_image_to_window(game->mlx, game->win, game->map, 0, 0);
	mlx_loop(game->mlx);
}
