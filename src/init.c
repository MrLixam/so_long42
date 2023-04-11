/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:21:52 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/11 20:15:36 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char **map_to_list(char *map)
{
	int		fd;
	char	*buffer;
	char	*line;	
	char	**mapL;

	fd = open(map, 00);
	buffer = get_next_line(fd);
	while (buffer)
	{
		line = ft_strjoin(line, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	close(fd);
	mapL = ft_split(line, '\n');
	free(line);
	return (mapL);
}

void	init_background(t_background_img *back, void *mlx, void *win, char *map)
{
	int	s;

	s = 32;
	back->wall = mlx_xpm_file_to_image(mlx, "../res/rock.xpm", &s, &s);
	back->empty = mlx_xpm_file_to_image(mlx, "../res/grass.xpm", &s, &s);
	back->coll = mlx_xpm_file_to_image(mlx, "../res/tacos.xpm", &s, &s);
	back->exit = mlx_xpm_file_to_image(mlx, "../res/sombrero.xpm", &s, &s);
	back->mlx = mlx;
	back->win = win;
	back->map = map_to_list(map);
}

static void	init_player_pos(t_player *player, char **map)
{
	int y;
	int x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				player->x = x;
				player->y = y;
			}
			x++;
		}
		y++;
	}
}

void	init_player(t_player *player, void *mlx, char *map)
{
	int s;
	s = 32;
	player->north = mlx_xpm_file_to_image(mlx, "../res/capibaraU.xpm", &s, &s);
	player->south = mlx_xpm_file_to_image(mlx, "../res/capibaraD.xpm", &s, &s);
	player->west = mlx_xpm_file_to_image(mlx, "../res/capibara.xpm", &s, &s);
	player->east = mlx_xpm_file_to_image(mlx, "../res/capibaraR.xpm", &s, &s);
	init_player_pos(player, map);
}
