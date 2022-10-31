/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:32:10 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/31 17:12:27 by ademurge         ###   ########.fr       */
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

void	check_pos(t_game *game)
{
	int	nb_player;
	int	nb_exit;
	int	nb_item;
	int	i;
	int	j;

	nb_player = 0;
	nb_exit = 0;
	i = -1;
	nb_item = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == PLAYER)
				nb_player++;
			if (game->map[i][j] == EXIT)
				nb_exit++;
			if (game->map[i][j] == ITEM)
				nb_item++;
		}
	}
	if (!nb_player || !nb_exit || nb_player > 1 || nb_exit > 1 || !nb_item)
		ft_error("Invalid map", game);
}

void	check_wall(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		c = 0;
		if (game->map[i][0] != WALL || game->map[i][game->length - 1] != WALL)
			ft_error("Invalid map", game);
		while (game->map[i][++j])
		{
			if (game->map[0][j] != WALL ||
				game->map[game->width - 1][j] != WALL)
				ft_error("Invalid map", game);
			if (!ft_strchr(VALID_CHARACTERS, game->map[i][j]))
				ft_error("Invalid map", game);
			c++;
		}
		if (c != game->length)
			ft_error("Invalid map", game);
	}
}

void	check(int ac, char **av, t_game *game)
{
	game->is_mlx = NO;
	if (ac != 2)
		ft_error("Wrong number of arguments", NULL);
	if (ft_strlen(ft_strstr(av[1], ".ber")) != 4)
		ft_error("Wrong file extension ", NULL);
	game->map = read_file(av[1]);
	game->length = ft_strlen(game->map[0]);
	game->width = ft_map_width(game->map);
	check_pos(game);
	check_wall(game);
}
