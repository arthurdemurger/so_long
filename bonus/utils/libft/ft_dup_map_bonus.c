/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:53:43 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/10 13:30:02 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

char	**ft_dup_map(char **map)
{
	int		i;
	char	**dup;
	int		height;

	height = ft_map_height(map);
	dup = malloc(sizeof(char *) * (height + 1));
	if (!dup)
		ft_error("Malloc error", NULL);
	dup[height] = NULL;
	i = -1;
	while (++i < height)
		dup[i] = ft_strdup(map[i]);
	dup[i] = 0;
	return (dup);
}
