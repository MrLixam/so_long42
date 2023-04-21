/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:08:02 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/21 18:35:29 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "keycodes.h"

static void	move_player(int x, int y, t_data *data)
{
	char	**map;
	int 	pos[2];

	map = data->background->map;
	pos[0] = data->player->x;
	pos[1] = data->player->y;
	if (map[pos[0] + x][pos[1] + y] != '1')
	{
		pos[0] += x;
		pos[1] += y;
		data->player->moves += 1;
	}
}

static void	handle_movement(int key, t_data *data)
{
	if (key == K_A)
		move_player(-1, 0, data);
	else if (key == K_D)
		move_player(1, 0, data);
	else if (key == K_S)
		move_player(0, -1, data);
	else
		move_player(0, 1, data);
}

int	handle_inputs(int key, t_data *data)
{
	/*if (key == K_ESC)
		end(data);*/
	if ((key == K_A || key == K_D) || (key == K_W || key == K_S))
		handle_movement(key, data);
	return (0);
}