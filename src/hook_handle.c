/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamv <liamv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:08:02 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/22 02:28:15 by liamv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "keycodes.h"

static void	move_player(int x, int y, t_data *data)
{
	char	**map;
	t_background_img *b;
	t_player	*p;

	b = data->background;
	map = b->map;
	p = data->player;
	if (map[p->y + y][p->x + x] != '1')
	{
		p->x += x;
		p->y += y;
		data->player->moves += 1;
		if (map[p->y][p->x] == 'C')
		{
			map[p->y][p->x] = '0';
			b->collected++;
		}
		game_loop(data);
	}
}

static void	handle_movement(int key, t_data *data)
{
	if (key == K_A)
	{
		move_player(-1, 0, data);
		data->player->ori = 'W';
	}
	else if (key == K_D)
	{
		move_player(1, 0, data);
		data->player->ori = 'E';
	}	
	else if (key == K_S)
	{
		move_player(0, 1, data);
		data->player->ori = 'S';
	}
	else
	{
		move_player(0, -1, data);
		data->player->ori = 'N';
	}
}

static void free_map(t_data *data)
{
	int			i;
	char	**map;

	i = -1;
	map = data->background->map;
	while (map[++i])
		free(map[i]);
	free(map);
}

static void	end(t_data *data)
{
	void *mlx;
	t_background_img *b;
	t_player *p;

	p = data->player;
	b = data->background;
	mlx = data->mlx;
	mlx_loop_end(mlx);
	mlx_destroy_window(mlx, data->win);
	mlx_destroy_image(mlx, p->west);
	mlx_destroy_image(mlx, p->east);
	mlx_destroy_image(mlx, p->south);
	mlx_destroy_image(mlx, p->north);
	mlx_destroy_image(mlx, b->empty);
	mlx_destroy_image(mlx, b->wall);
	mlx_destroy_image(mlx, b->coll);
	mlx_destroy_image(mlx, b->exit);
	mlx_destroy_display(mlx);
	free(mlx);
	free_map(data);
	exit(EXIT_SUCCESS);
}

int	handle_inputs(int key, t_data *data)
{
	if (key == K_ESC)
		end(data);
	if ((key == K_A || key == K_D) || (key == K_W || key == K_S))
		handle_movement(key, data);
	return (0);
}
