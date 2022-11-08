/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:45:56 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/08 13:46:50 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**read_file(char *file)
{
	char	**split;
	char	*join;
	char	*tmp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Open error.", NULL);
	join = get_next_line(fd);
	if (!join || join[0] == '\n')
		ft_error("Invalid map.", NULL);
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (tmp[0] == '\n')
			ft_error("Invalid map", NULL);
		join = gnl_strjoin(join, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	split = ft_split(join, '\n');
	if (join)
		free(join);
	close(fd);
	return (split);
}
