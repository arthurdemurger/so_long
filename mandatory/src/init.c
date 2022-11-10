/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:06:29 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/10 13:50:23 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game(t_game *game)
{
	int		i;
	int		j;

	game->nb_items = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (game->map[i][j] == ITEM)
				game->nb_items++;
	}
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * SIZE_SQR,
			game->height * SIZE_SQR, "map 42 - ademurge");
	game->check.is_mlx = YES;
	game->sqr_size = SIZE_SQR;
	game->nb_move = 0;
	game->exit_status = CLOSED;
	game->check.is_game_over = NO;
	game->count = 0;
	game->status = PLAYING;
}

void	init_map_sqr(t_game *game)
{
	int	i;

	game->map_sqr = malloc(sizeof(void **) * (game->height + 1));
	i = -1;
	while (++i < game->height)
		game->map_sqr[i] = malloc (sizeof(void *) * (game->width + 1));
	game->map_sqr[i] = NULL;
}
