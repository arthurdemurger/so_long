/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:49:16 by ademurge          #+#    #+#             */
/*   Updated: 2022/09/28 15:35:00 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_strlcpy(char *dest, const char *src, int size)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (src[c])
		c++;
	if (size)
	{
		while (src[++i] && i < (size - 1))
			dest[i] = src[i];
		dest[i] = 0;
	}
	return (c);
}
