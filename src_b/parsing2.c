/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:53:35 by liamv             #+#    #+#             */
/*   Updated: 2023/05/09 16:41:54 by lvincent         ###   ########.fr       */
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
	char	**map;
	int		found[2];
	int		xy[2];

	map = map_to_list(to_parse);
	xy[1] = -1;
	while (map[++xy[1]])
	{
		xy[0] = -1;
		while (map[xy[1]][++xy[0]])
			if (map[xy[1]][xy[0]] == 'P')
				break ;
		if (map[xy[1]][xy[0]] == 'P')
			break ;
	}
	found[0] = ft_dfs_search(map, xy[0], xy[1], 'E');
	free_map(map);
	if (found[0] != 1)
		ft_error("No valid path to exit!");
	map = map_to_list(to_parse);
	found[1] = count_a_char(map, 'C');
	found[0] = ft_dfs_search(map, xy[0], xy[1], 'C');
	free_map(map);
	if (found[0] != found[1])
		ft_error("One or multiple collectibles are inaccessible!");
}
