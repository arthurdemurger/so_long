/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:47:51 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/10 13:31:06 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*src;
	char	*str;
	int		size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(&s[start]);
	if (size > len)
		size = len;
	src = (char *)s;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		ft_error("Malloc error ", NULL);
	ft_strlcpy(str, &src[start], size + 1);
	return (str);
}
