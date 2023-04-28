/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:53:35 by liamv             #+#    #+#             */
/*   Updated: 2023/04/28 16:25:49 by liamv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_a_char(char **map, char find)
{
	int	x;
	int	y;
	int	count;

	y = -1;
	count = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == find)
				count++;
	}
	return (count);
}

void	parse3(char *to_parse)
{
	char 	**map;
	int	found[2];
	int	x;
	int	y;

	map = map_to_list(to_parse);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'P')
				break ;
		if (map[y][x])
			break ;
	}
	found[0] = ft_dfs_search(map, x, y, 'E');
	free_map(map);
	if (found[0] != 1)
		ft_error("No valid path to exit!");
	map = map_to_list(to_parse);
	found[1] = count_a_char(map, 'C');
	found[0] = ft_dfs_search(map, x, y, 'C');
	free_map(map);
	if (found[0] != found[1])
		ft_error("One or multiple Collectibles are inaccessible");
}
