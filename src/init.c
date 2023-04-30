/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamv <liamv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:21:52 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/29 18:59:47 by liamv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char     *ft_strrejoin(char *s1, char *s2)
{
        char    *rv;

        if (!s1)
        {
                rv = malloc(ft_strlen(s2) + 1);
                if (!rv)
                        return (NULL);
                rv[ft_strlen(s2)] = '\0';
                ft_memcpy(rv, s2, ft_strlen(s2));
                return (rv);
        }
        if (!s2)
                return (s1);
        rv = malloc(1 + ft_strlen(s1) + ft_strlen(s2));
        if (!rv)
                return (NULL);
        ft_memcpy(rv, s1, ft_strlen(s1));
        ft_memcpy(rv + ft_strlen(s1), s2, ft_strlen(s2) + 1);
        if (rv[ft_strlen(s1) + ft_strlen(s2)] != '\0')
                rv[ft_strlen(s1) + ft_strlen(s2)] = '\0';
        free(s1);
        return (rv);
}


char **map_to_list(char *map)
{
	int		fd;
	char	*buffer;
	char	*line;	
	char	**mapL;

	fd = open(map, 00);
	line = ft_strdup("");
	buffer = get_next_line(fd);
	while (buffer)
	{
		line = ft_strrejoin(line, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	close(fd);
	mapL = ft_split(line, '\n');
	free(line);
	return (mapL);
}

static void	init_pos(t_data *data, char **map)
{
	int			y;
	int			x;
	t_player		*p;

	p = data->player;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				p->x = x;
				p->y = y;
			}	
			else if (map[y][x] ==  'C' )
				data->background->coll_end++;
			x++;
		}
		y++;
	}
}

static void	check_img(t_data *data)
{
	t_player *p;
	t_background_img *b;

	p = data->player;
	b = data->background;
	if ((!b->wall || !b->empty) || (!b->coll || !b->exit))
	{
		end(data);
		ft_error("There was a problem getting map textures");
	}
	if ((!p->east || !p->west) || (!p->south || !p->north))
	{
		end(data);
		ft_error("There was a problem getting player textures");
	}
}

void	init(t_data *data, char *map)
{
	int s;
	t_player	*p;
	t_background_img	*back;

	s = 32;
	p = data->player;
	back = data->background;
	back->wall = mlx_xpm_file_to_image(data->mlx, "./res/rock.xpm", &s, &s);
	back->empty = mlx_xpm_file_to_image(data->mlx, "./res/grass.xpm", &s, &s);
	back->coll = mlx_xpm_file_to_image(data->mlx, "./res/tacos.xpm", &s, &s);
	back->exit = mlx_xpm_file_to_image(data->mlx, "./res/sombrero.xpm", &s, &s);
	back->coll_end = 0;
	back->collected = 0;
	back->map = map_to_list(map);
	p->north = mlx_xpm_file_to_image(data->mlx, "./res/capibaraU.xpm", &s, &s);
	p->south = mlx_xpm_file_to_image(data->mlx, "./res/capibaraD.xpm", &s, &s);
	p->west = mlx_xpm_file_to_image(data->mlx, "./res/capibara.xpm", &s, &s);
	p->east = mlx_xpm_file_to_image(data->mlx, "./res/capibaraR.xpm", &s, &s);
	init_pos(data, data->background->map);
	p->ori = 'W';
	p->moves = 0;
	check_img(data);
}
