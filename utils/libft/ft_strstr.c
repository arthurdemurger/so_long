/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:31:08 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/13 23:41:03 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	*ft_strstr(char *big, char *little)
{
	int	i;
	int	j;

	i = 0;
	if (!*little)
		return (big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (!little[j])
				return (&big[i]);
			j++;
		}
		if (!little[j])
			return (&big[i]);
		i++;
	}
	return (NULL);
}
