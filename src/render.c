/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:11:35 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/19 17:22:15 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void choice_player(t_player p)
{
	char ori;
	void *mlx;
	void *win;

	ori = p.ori;
	mlx = p.data.mlx;
	win = p.data.win;
	if (ori == 'W')
		mlx_put_image_to_window(mlx, win, p.west, p.x * 32, p.y * 32);
	else if (ori == 'E')
		mlx_put_image_to_window(mlx, win, p.east, p.x * 32, p.y * 32);
	else if (ori == 'S')
		mlx_put_image_to_window(mlx, win, p.south, p.x * 32, p.y * 32);
	else
		mlx_put_image_to_window(mlx, win, p.north, p.x * 32, p.y * 32);
}

static void	choice_bground(char c, t_background_img bgrd, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = bgrd.data.mlx;
	win = bgrd.data.win;
	if (c == '0' || c == 'P')
		mlx_put_image_to_window(mlx, win, bgrd.empty, x * 32, y * 32);
	else if (c == '1')
		mlx_put_image_to_window(mlx, win, bgrd.wall, x * 32, y * 32);
	else if (c == 'C')
		mlx_put_image_to_window(mlx, win, bgrd.coll, x * 32, y * 32);
	else if (c == 'E')
		mlx_put_image_to_window(mlx, win, bgrd.exit, x * 32, y * 32);		
}

void	render_frame(t_background_img background)
{
	int		x;
	int		y;

	y = 0;
	while (background.map[y])
	{
		x = -1;
		while (background.map[y][++x])
			choice_bground(background.map[y][x], background, x, y);
		y++;
	}
}

/*void	render_player(t_player *player, char **map)
{

}*/
