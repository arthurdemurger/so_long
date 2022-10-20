/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:51:33 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/20 15:39:47 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	replace_sqr(t_game *game, int x, int y, char *xpm_file)
{
	mlx_destroy_image(game->mlx, game->map_sqr[y][x].img);
	game->map_sqr[y][x].img = mlx_xpm_file_to_image(game->mlx, xpm_file,
			&game->sqr_size, &game->sqr_size);
	mlx_put_image_to_window(game->mlx, game->win, game->map_sqr[y][x].img,
		x * 64, y * 64);
}

void	move_player(t_game *game, int new_x, int new_y, char *direction)
{
	int	x;
	int	y;

	x = game->player_pos.x;
	y = game->player_pos.y;
	replace_sqr(game, x, y, BACKGROUND_XPM);
	replace_sqr(game, new_x, new_y, PLAYER_XPM);
	game->map[y][x] = BACKGROUND;
	game->map[new_y][new_x] = PLAYER;
	game->player_pos.x = new_x;
	game->player_pos.y = new_y;
	ft_printf("Move %s |  Total of moves : %i\n", direction, ++game->nb_move);
}

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
	game->sqr_size = 64;
	game->nb_move = 0;
	return (pos);
}

void	start_game(t_game *game)
{
	init_mlx(game);
	init_map_sqr(game);
	game->player_pos = init_game(game);
	draw_map(game);
	controls (game);
}
