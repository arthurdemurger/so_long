/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:15:51 by ademurge          #+#    #+#             */
/*   Updated: 2022/09/29 22:16:50 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_data *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1920, 1080, "map 42 - ademurge");
	map->img.img = mlx_new_image(map->mlx, 1920, 1080);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pix,
			&map->img.line_length, &map->img.endian);
}
