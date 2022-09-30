/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:42:08 by ademurge          #+#    #+#             */
/*   Updated: 2022/09/30 10:10:26 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	if (!s2)
		return (s1);
	if (!s1)
		return (ft_strdup(s2));
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		perror("Malloc error");
	i = -1;
	j = 0;
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = 0;
	free(s1);
	return (dst);
}
