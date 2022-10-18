/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:51:33 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/18 15:36:09 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_coord	init_game(t_game *game)
{
	int		i;
	int		j;
	t_coord	pos;

	game->nb_items = 0;
	game->exit.status = CLOSED;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				pos.x = i;
				pos.y = j;
			}
			if (game->map[i][j] == 'C')
				game->nb_items++;
		}
	}
	game->sqr_size = 64;
	return (pos);
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

void	start_game(t_game *game)
{
	init_mlx(game);
	init_map_sqr(game);
	game->player.pos = init_game(game);
	draw_map(game);
	controls (game);
}
