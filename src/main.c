/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:45:55 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/21 19:09:58 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*alloc_b(t_background_img *back)
{
	back->collected = malloc(sizeof(int));
}

static void	*alloc_p(t_player *player)
{
	player->x = malloc(sizeof(int));
	player->y = malloc(sizeof(int));
	player->moves = malloc(sizeof(int));
	player->ori = malloc(sizeof(char));
}

int main(int argc, char **argv)
{
	t_data				data;
	t_background_img	b;
	t_player			p;


	/*if (parse(argv[1]) == -1)
		return (-1);*/
	alloc_b(&b);
	alloc_p(&p);
	data.background = &b;
	data.player = &p;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "MAIN");
	init_background(&data, "../maps/small.ber");
	init_player(&data);
	render_frame(&data);
	mlx_hook(data.win, 2, 1L<<0, handle_inputs, &main);
	mlx_loop(data.mlx);
	return (0);
}