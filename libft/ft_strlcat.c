/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:15:28 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/31 19:13:08 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_strlcat(char *dest, char *src, int size)
{
	int	i;
	int	j;
	int	size_dest;
	int	size_src;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size_dest > size || !src || !dest)
		return (size_src + size);
	j = 0;
	i = size_dest;
	while (src[j] && i + 1 < size)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (size_src + size_dest);
}
