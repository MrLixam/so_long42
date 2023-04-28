/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamv <liamv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:45:55 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/28 17:04:22 by liamv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data				data;
	t_background_img	b;
	t_player		p;

	if (argc != 2)
		ft_error("Wrong command!\nCommand usage: ./so_long <map_path>");
	parse(argv[1]);
	data.player = &p;
	data.background = &b;
	data.mlx = mlx_init();
	init(&data, argv[1]);
	data.win = mlx_new_window(data.mlx, data.dim[1], data.dim[0], "YEAH BUDDY");
	game_loop(&data);
	mlx_hook(data.win, 2, 1L<<0, handle_inputs, &data);
	mlx_loop(data.mlx);
	return (0);
}
