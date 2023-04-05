/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:21:52 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/05 15:45:22 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static void	map_to_list(t_background_img *back, char *map)
{
	int	fd;
	int	i;

	fd = open(map, 00);
	i = 0;
	while (1)
	{
		back->map[i] = get_next_line(fd);
		if (back->map[i] == NULL)
			break ;
		i++;
	}
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
	map_to_list(back, map);
}
static void	init_player_pos(t_player *player, char **map)
{
	int i;
	int j;

	i = 0;	
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_player(t_player *player, void *mlx, char **map)
{
	int s;
	s = 32;
	player->north = mlx_xpm_file_to_image(mlx, "../res/capibaraU.xpm", &s, &s);
	player->south = mlx_xpm_file_to_image(mlx, "../res/capibaraD.xpm", &s, &s);
	player->west = mlx_xpm_file_to_image(mlx, "../res/capibara.xpm", &s, &s);
	player->east = mlx_xpm_file_to_image(mlx, "../res/capibaraR.xpm", &s, &s);
	init_player_pos(player, map);
}
