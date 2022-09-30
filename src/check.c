/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:32:10 by ademurge          #+#    #+#             */
/*   Updated: 2022/09/30 12:22:26 by ademurge         ###   ########.fr       */
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
	tmp = get_next_line(fd);
	if (!tmp)
		ft_error("Invalid map.", NULL);
	join = tmp;
	tmp = get_next_line(fd);
	while (tmp)
	{
		join = ft_strjoin(join, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	split = ft_split(join, '\n');
	if (join)
		free(join);
	close(fd);
	return (split);
}

void	check_pos(char **map)
{
	int	p;
	int	e;
	int	c;
	int	i;
	int	j;

	p = 0;
	e = 0;
	i = -1;
	c = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				c++;
		}
	}
	if (!p || !e || p > 1 || e > 1 || !c)
		ft_error("Invalid map.", map);
}

void	check_wall(t_data *map)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		c = 0;
		if (map->map[i][0] != '1' || map->map[i][map->length - 1] != '1')
			ft_error("Invalid map.", map->map);
		while (map->map[i][++j])
		{
			if (map->map[0][j] != '1' || map->map[map->width - 1][j] != '1')
				ft_error("Invalid map.", map->map);
			c++;
		}
		if (c != map->length)
			ft_error("Invalid map.", map->map);
	}
}

void	check(int ac, char **av, t_data *map)
{
	(void) av;
	(void) map;
	if (ac != 2)
		ft_error("Wrong number of arguments ", NULL);
	if (ft_strlen(ft_strstr(av[1], ".ber")) != 4)
		ft_error("Wrong file extension ", NULL);
	map->map = read_file(av[1]);
	map->length = ft_strlen(map->map[0]);
	map->width = ft_map_width(map->map);
	check_pos(map->map);
	check_wall(map);
}
