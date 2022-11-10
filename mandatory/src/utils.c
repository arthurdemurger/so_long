/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:45:56 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/09 00:28:05 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_coord	coord_to_pos(int x, int y)
{
	t_coord	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

void	put_img(t_game *game, int x, int y, char *file)
{
	int	*size;

	size = &game->sqr_size;
	game->map_sqr[y][x] = mlx_xpm_file_to_image(game->mlx, file, size, size);
	mlx_put_image_to_window(game->mlx, game->win, game->map_sqr[y][x],
		x * SIZE_SQR, y * SIZE_SQR);
}

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
