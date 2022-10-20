/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:06:29 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/19 22:29:02 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->length * 64, game->width * 64,
			"map 42 - ademurge");
}

void	init_map_sqr(t_game *game)
{
	int	i;

	game->map_sqr = malloc(sizeof(t_img *) * (game->width + 1));
	i = -1;
	while (++i < game->width)
		game->map_sqr[i] = malloc (sizeof(t_img) * (game->length + 1));
}
