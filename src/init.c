/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:06:29 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/31 18:24:22 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_coord	init_game(t_game *game)
{
	int		i;
	int		j;
	t_coord	pos;

	game->nb_items = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == PLAYER)
			{
				pos.x = j;
				pos.y = i;
			}
			if (game->map[i][j] == ITEM)
				game->nb_items++;
		}
	}
	game->sqr_size = 80;
	game->nb_move = 0;
	game->exit_status = CLOSED;
	return (pos);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->length * 80, game->width * 80,
			"map 42 - ademurge");
	game->is_mlx = YES;
}

void	init_map_sqr(t_game *game)
{
	int	i;

	game->map_sqr = malloc(sizeof(t_img *) * (game->width + 1));
	i = -1;
	while (++i < game->width)
		game->map_sqr[i] = malloc (sizeof(t_img) * (game->length + 1));
}
