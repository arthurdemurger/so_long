/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:01:48 by ademurge          #+#    #+#             */
/*   Updated: 2022/09/30 11:09:42 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_line_break(char *str)
{
	while (str && *str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

char	*gnl_strjoin(char *stash, char *buf)
{
	char	*dst;
	int		i;
	int		j;

	if (!stash)
		return (ft_strdup(buf));
	if (!*buf)
		return (stash);
	dst = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	if (!dst)
		ft_error("Malloc error ", NULL);
	i = -1;
	j = 0;
	while (stash[++i])
		dst[i] = stash[i];
	while (buf[j])
		dst[i++] = buf[j++];
	dst[i] = 0;
	free(stash);
	return (dst);
}

char	*gnl_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		ft_error("Malloc error.", NULL);
	i = -1;
	while (++i < len)
		str[i] = s[start + i];
	str[i] = 0;
	return (str);
}
