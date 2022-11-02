/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:42:08 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/02 15:16:13 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)malloc(sizeof(char) * size);
	if (!dst)
		ft_error("Malloc error", NULL);
	ft_strlcpy(dst, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(dst, (char *)s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return (dst);
}
