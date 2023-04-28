/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamv <liamv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:08:02 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/27 17:22:52 by liamv            ###   ########.fr       */
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
		if (map[p->y][p->x] == 'E' && b->collected == b->coll_end)
			end(data);
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

int	handle_inputs(int key, t_data *data)
{
	if (key == K_ESC)
		end(data);
	if ((key == K_A || key == K_D) || (key == K_W || key == K_S))
		handle_movement(key, data);
	return (0);
}
