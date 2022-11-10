/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:51:33 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/10 13:24:02 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	put_nb_moves(t_game *game, char *direction)
{
	int		i;
	char	*nb;
	char	*str;

	ft_printf("Move %s |  Total number of moves : %i\n", direction,
		++game->nb_move);
	i = -1;
	while (++i < 2)
	{
		mlx_destroy_image(game->mlx, game->map_sqr[0][i]);
		game->map_sqr[0][i] = mlx_xpm_file_to_image(game->mlx, WALL_XPM,
				&game->sqr_size, &game->sqr_size);
		mlx_put_image_to_window(game->mlx, game->win, game->map_sqr[0][i],
			i * SIZE_SQR, 0);
	}
	nb = ft_itoa(game->nb_move);
	str = ft_strjoin("Moves : ", nb);
	mlx_string_put(game->mlx, game->win, 0, 0, 0xFFFFFF, str);
	free(nb);
	free(str);
}

void	replace_sqr(t_game *game, t_coord pos, t_coord new_pos, char *xpm_file)
{
	mlx_destroy_image(game->mlx, game->map_sqr[pos.y][pos.x]);
	mlx_destroy_image(game->mlx, game->map_sqr[new_pos.y][new_pos.x]);
	game->map_sqr[pos.y][pos.x] = mlx_xpm_file_to_image(game->mlx,
			BACKGROUND_XPM, &game->sqr_size, &game->sqr_size);
	mlx_put_image_to_window(game->mlx, game->win, game->map_sqr[pos.y][pos.x],
		pos.x * SIZE_SQR, pos.y * SIZE_SQR);
	game->map_sqr[new_pos.y][new_pos.x] = mlx_xpm_file_to_image(game->mlx,
			xpm_file, &game->sqr_size, &game->sqr_size);
	mlx_put_image_to_window(game->mlx, game->win,
		game->map_sqr[new_pos.y][new_pos.x],
		new_pos.x * SIZE_SQR, new_pos.y * SIZE_SQR);
	game->map[new_pos.y][new_pos.x] = game->map[pos.y][pos.x];
	game->map[pos.y][pos.x] = BACKGROUND;
}

void	move_player(t_game *game, t_coord pos, char *direction)
{
	t_coord	pl_pos;

	pl_pos = game->player_pos;
	if (!ft_strcmp(direction, MV_UP))
		replace_sqr(game, pl_pos, pos, PL_UP_XPM);
	else if (!ft_strcmp(direction, MV_DOWN))
		replace_sqr(game, pl_pos, pos, PL_DOWN_XPM);
	else if (!ft_strcmp(direction, MV_LEFT))
		replace_sqr(game, pl_pos, pos, PL_LEFT_XPM);
	else if (!ft_strcmp(direction, MV_RIGHT))
		replace_sqr(game, pl_pos, pos, PL_RIGHT_XPM);
	game->player_pos = pos;
	put_nb_moves(game, direction);
}

void	move_or_not(t_game *game, int x, int y, char *direction)
{
	t_coord	pos;

	pos.x = x;
	pos.y = y;
	if (game->map[y][x] == BACKGROUND)
		move_player(game, pos, direction);
	else if (game->map[y][x] == ITEM)
	{
		game->nb_items--;
		move_player(game, pos, direction);
		if (!game->nb_items && game->exit_status == CLOSED)
		{
			game->exit_pos = ft_find_pos(game, EXIT);
			mlx_destroy_image(game->mlx,
				game->map_sqr[game->exit_pos.y][game->exit_pos.x]);
			put_img(game, game->exit_pos.x, game->exit_pos.y, OPEN_EXIT_XPM);
			game->exit_status = OPEN;
		}
	}
	else if (game->map[y][x] == EXIT && game->exit_status == OPEN)
		draw_end(game, WIN);
	else if (game->map[y][x] == GHOST)
		draw_end(game, LOSE);
}

void	start_game(t_game *game)
{
	init_mlx(game);
	init_map_sqr(game);
	init_game(game);
	draw_map(game);
	controls(game);
}
