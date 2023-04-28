/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:11:35 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/21 18:35:12 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void player_choice(t_data *data)
{
	char ori;
	void *mlx;
	void *win;
	t_player *p;

	p = data->player;
	mlx = data->mlx;
	win = data->win;
	ori = p->ori;
	if (ori == 'W')
		mlx_put_image_to_window(mlx, win, p->west, p->x * 32, p->y * 32);
	else if (ori == 'E')
		mlx_put_image_to_window(mlx, win, p->east, p->x * 32, p->y * 32);
	else if (ori == 'S')
		mlx_put_image_to_window(mlx, win, p->south, p->x * 32, p->y * 32);
	else
		mlx_put_image_to_window(mlx, win, p->north, p->x * 32, p->y * 32);
}

static void	choice_bground(char c, t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;
	t_background_img *b;
	
	b = data->background;
	mlx = data->mlx;
	win = data->win;
	if (c == '0' || c == 'P')
		mlx_put_image_to_window(mlx, win, b->empty, x * 32, y * 32);
	else if (c == '1')
		mlx_put_image_to_window(mlx, win, b->wall, x * 32, y * 32);
	else if (c == 'C')
		mlx_put_image_to_window(mlx, win, b->coll, x * 32, y * 32);
	else if (c == 'E')
		mlx_put_image_to_window(mlx, win, b->exit, x * 32, y * 32);		
}

void	render_frame(t_data *data)
{
	int		x;
	int		y;
	t_background_img *b;

	b = data->background;
	y = 0;
	while (b->map[y])
	{
		x = -1;
		while (b->map[y][++x])
			choice_bground(b->map[y][x], data, x, y);
		y++;
	}
}

int	game_loop(t_data *data)
{
	render_frame(data);
	player_choice(data);
	return (0);
}
