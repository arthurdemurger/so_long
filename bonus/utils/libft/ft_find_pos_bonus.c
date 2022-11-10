/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:57:05 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/10 13:30:04 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

t_coord	ft_find_pos(t_game *game, char block)
{
	t_coord	pos;
	int		i;
	int		j;

	i = -1;
	pos.x = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (game->map[i][j] == block)
				pos = coord_to_pos(j, i);
	}
	return (pos);
}
