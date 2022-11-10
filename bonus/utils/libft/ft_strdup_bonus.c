/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:48:50 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/10 13:30:47 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

char	*ft_strdup(char *src)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!str)
		ft_error("Malloc error ", NULL);
	ft_strlcpy(str, src, ft_strlen(src) + 1);
	return (str);
}
