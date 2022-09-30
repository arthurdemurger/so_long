/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:17:03 by ademurge          #+#    #+#             */
/*   Updated: 2022/09/29 22:17:54 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	keypress(int keycode, t_data *map)
{
	if (keycode == ESC)
		close_win(map);
	return (0);
}

void	controls(t_data *map)
{
	mlx_hook(map->win, DESTROY_BUTTON, 0, close_win, map);
	mlx_hook(map->win, KEYPRESS, 0, keypress, map);
}
