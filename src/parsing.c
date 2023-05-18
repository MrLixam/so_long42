/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:49:54 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/18 17:35:23 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_elements(char **map)
{	
	int	all[3];
	int	x;
	int	y;

	ft_bzero(all, 3 * sizeof(int));
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
				all[0] = 1;
			else if (map[y][x] == 'P')
				all[1]++;
			else if (map[y][x] == 'E')
				all[2]++;
			else if (map[y][x] != '1' && map[y][x] != '0')
				return (1);
		}
	}
	if ((all[0] + all[1] + all[2]) != 3)
		return (1);
	return (0);
}

static int	not_rectangle(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[++i])
		if (ft_strlen(map[i]) != len)
			return (1);
	return (0);
}

static int	map_walls(char **map)
{
	int	xy[2];
	int	last;

	xy[0] = -1;
	last = ft_strlen(map[0]) - 1;
	while (map[0][++xy[0]])
		if (map[0][xy[0]] != '1')
			return (1);
	xy[1] = -1;
	while (map[++xy[1]])
		if (map[xy[1]][0] != '1' || map[xy[1]][last] != '1')
			return (1);
	xy[0] = -1;
	xy[1]--;
	while (map[xy[1]][++xy[0]])
		if (map[xy[1]][xy[0]] != '1')
			return (1);
	return (0);
}

static void	parse2(char *to_parse)
{
	char	**map;

	map = map_to_list(to_parse);
	if (map[0] == NULL)
	{
		free_map(map);
		ft_error("File is empty!");
	}
	if (not_rectangle(map))
	{
		free_map(map);
		ft_error("Map is not rectangular!");
	}
	if (map_elements(map))
	{
		free_map(map);
		ft_error("Some elements on the map are missing or are incorrect!");
	}
	if (ft_strlen(map[0]) < 3 || map_walls(map))
	{
		free_map(map);
		ft_error("The map borders must be walls!");
	}
	free_map(map);
	parse3(to_parse);
}

void	parse(char *to_parse)
{
	int	fd;

	fd = open(to_parse, 00);
	if (fd == -1)
	{
		close(fd);
		ft_error("The file is un-openable or doesn't exist!");
	}
	close(fd);
	if (ft_strncmp(ft_strrchr(to_parse, '.'), ".ber", 4))
		ft_error("Wrong File Format!");
	parse2(to_parse);
}
