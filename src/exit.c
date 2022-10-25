/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:29:06 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/25 17:24:58 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_maps(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map && game->map[++i])
		free(game->map[i]);
	if (game->map)
		free(game->map);
	i = -1;
	while (++i < game->width)
	{
		j = -1;
		while (++j < game->length)
			mlx_destroy_image(game->mlx, game->map_sqr[i][j].img);
	}
}

void	ft_error(char *type, t_game *game)
{
	ft_putendl_fd(type, STDERR_FILENO);
	end_game(game, EXIT_FAILURE);
}

int	end_game(t_game *game, int type_exit)
{
	mlx_destroy_window(game->mlx, game->win);
	free_maps(game);
	system("leaks so_long");
	exit(type_exit);
}
