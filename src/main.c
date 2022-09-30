/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:06:00 by ademurge          #+#    #+#             */
/*   Updated: 2022/09/30 12:22:44 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_data	map;

	check(ac, av, &map);
	init_mlx(&map);
	controls(&map);
	//mlx_put_image_to_window(map.mlx, map.win, map.img.img, 400, 400);
	mlx_loop(map.mlx);
	return (0);
}
