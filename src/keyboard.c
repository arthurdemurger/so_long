/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:17:03 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/18 16:07:44 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
void	up_pos(t_game *game)
{
	if (game->map[game->player.pos.y - 1][game->player.pos.x] == WALL)
		return ;
	else
		printf("%c\n", game->map[0][4]);
}

void	down_pos(t_data *map);
{
	// code
}

void	left_pos(t_data *map);
{
	// code
}

void	right_pos(t_data *map);
{
	// code
}
*/

int	keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_win(game);
	//else if (keycode == W)
	//	up_pos(game);
	//else if (keycode == A)
	//	down_pos(map);
	//else if (keycode == S)
	//	left_pos(map);
	//else if (keycode == D)
	//	right_pos(map);
	return (0);
}

void	controls(t_game *game)
{
	mlx_hook(game->win, KEYPRESS, 0, keypress, game);
	mlx_hook(game->win, DESTROY_BUTTON, 0, close_win, game);
}
