/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamv <liamv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:21:52 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/22 02:24:07 by liamv            ###   ########.fr       */
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
	line = "";
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

t_background_img	init_background(t_data *data, char *map)
{
	int	s;
	t_background_img back;

	s = 32;
	back.wall = mlx_xpm_file_to_image(data->mlx, "../res/rock.xpm", &s, &s);
	back.empty = mlx_xpm_file_to_image(data->mlx, "../res/grass.xpm", &s, &s);
	back.coll = mlx_xpm_file_to_image(data->mlx, "../res/tacos.xpm", &s, &s);
	back.exit = mlx_xpm_file_to_image(data->mlx, "../res/sombrero.xpm", &s, &s);
	back.map = map_to_list(map);
	back.collected = 0;
	return (back);
}

static t_player	init_player_pos(char **map)
{
	int			y;
	int			x;
	t_player	p;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				p.x = x;
				p.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
	return (p);
}

t_player	init_player(t_data data)
{
	int s;
	t_player p;

	s = 32;
	p.north = mlx_xpm_file_to_image(data.mlx, "../res/capibaraU.xpm", &s, &s);
	p.south = mlx_xpm_file_to_image(data.mlx, "../res/capibaraD.xpm", &s, &s);
	p.west = mlx_xpm_file_to_image(data.mlx, "../res/capibara.xpm", &s, &s);
	p.east = mlx_xpm_file_to_image(data.mlx, "../res/capibaraR.xpm", &s, &s);
	p = init_player_pos(data.background->map);
	p.ori = 'W';
	p.moves = 0;
	return (p);
}
