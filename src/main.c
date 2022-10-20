/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:06:00 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/20 10:33:45 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	check(ac, av, &game);
	start_game(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.map, 0, 0);
	mlx_loop(game.mlx);
	return (0);
}
