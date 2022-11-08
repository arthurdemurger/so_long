/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:32:10 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/08 16:19:07 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_block(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == ITEM)
		game->check.nb_items++;
	else if (map[y][x] == EXIT)
		game->check.is_exit = YES;
	if (x >= game->width || y >= game->height || x < 0 || y < 0
		|| map[y][x] == WALL || map[y][x] == CHECKED || map[y][x] == EXIT)
		return ;
	map[y][x] = CHECKED;
	check_block(game, map, x + 1, y);
	check_block(game, map, x - 1, y);
	check_block(game, map, x, y + 1);
	check_block(game, map, x, y - 1);
}

void	check_path(t_game *game)
{
	char	**tmp_map;

	game->check.nb_items = 0;
	game->check.is_exit = NO;
	tmp_map = ft_dup_map(game->map);
	check_block(game, tmp_map, game->player_pos.x, game->player_pos.y);
	if (game->check.is_exit == NO || game->check.nb_items != game->nb_items)
		ft_error("Invalid map. No valid path found.", game);
	free_map(tmp_map);
}

void	check_pos(t_game *game)
{
	if (ft_count(game, PLAYER) != 1)
		ft_error("There must be only one player on the map.", game);
	else if (ft_count(game, EXIT) != 1)
		ft_error("There must be only one exit on the map.", game);
	else if (ft_count(game, ITEM) <= 0)
		ft_error("There must be at least one item on the map.", game);
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
		if (game->map[i][0] != WALL || game->map[i][game->width - 1] != WALL)
			ft_error("Invalid map", game);
		while (game->map[i][++j])
		{
			if (game->map[0][j] != WALL ||
				game->map[game->height - 1][j] != WALL)
				ft_error("Invalid map", game);
			if (!ft_strchr(VALID_CHARACTERS, game->map[i][j]))
				ft_error("Invalid map", game);
			c++;
		}
		if (c != game->width)
			ft_error("Invalid map", game);
	}
}

void	check(int ac, char **av, t_game *game)
{
	game->check.is_mlx = NO;
	if (ac != 2)
		ft_error("Wrong number of arguments", NULL);
	if (ft_strlen(ft_strstr(av[1], ".ber")) != 4)
		ft_error("Wrong file extension ", NULL);
	game->map = read_file(av[1]);
	game->width = ft_strlen(game->map[0]);
	game->height = ft_map_height(game->map);
	game->player_pos = ft_find_pos(game, PLAYER);
	game->nb_items = ft_count(game, ITEM);
	check_pos(game);
	check_wall(game);
	check_path(game);
}
