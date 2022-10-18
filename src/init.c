/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:06:29 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/18 16:10:58 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->length * 64, game->width * 64,
			"map 42 - ademurge");
	//game->map_img.img = mlx_new_image(game->mlx, 1920, 1080);
	//game->map_img.addr = mlx_get_data_addr(game->map_img.img, &game->map_img.bits_per_pix,
	//		&game->map_img.line_length, &game->map_img.endian);
}

void	init_map_sqr(t_game *game)
{
	int	i;

	game->map_sqr = malloc(sizeof(t_img *) * game->width);
	i = -1;
	while (++i < game->length)
	{
		game->map_sqr[i] = malloc (sizeof(t_img) * game->length);
	}
}
