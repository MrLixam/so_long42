/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:11:35 by lvincent          #+#    #+#             */
/*   Updated: 2023/03/21 17:22:21 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_choice(char c, t_background_img bgrd, int x, int y)
{
	if (c == '0' || c == 'P')
		mlx_put_image_to_window(bgrd.mlx, bgrd.win, bgrd.empty, x * 32, y * 32);
	else if (c == '1')
		mlx_put_image_to_window(bgrd.mlx, bgrd.win, bgrd.wall, x * 32, y * 32);
	else if (c == 'C')
		mlx_put_image_to_window(bgrd.mlx, bgrd.win, bgrd.coll, x * 32, y * 32);
	else if (c == 'E')
		mlx_put_image_to_window(bgrd.mlx, bgrd.win, bgrd.exit, x * 32, y * 32);
}

void	background_render(char *map, t_background_img background)
{
	char	*line;
	int		x;
	int		y;
	int		fd;

	fd = open(map, 00);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		x = -1;
		while (line[++x])
			render_choice(line[x], background, x, y);
		y++;
		free(line);
		line = get_next_line(fd);
	}
}
