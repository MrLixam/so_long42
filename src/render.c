/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:11:35 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/05 15:39:58 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	choice_bground(char c, t_background_img bgrd, int x, int y)
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

void	background_render(t_background_img background)
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

void	player_overlay(t_player *player, t_background_img map)
{

}
