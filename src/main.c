/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamv <liamv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:45:55 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/22 02:23:07 by liamv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data				data;
	t_background_img	b;
	t_player			p;


	/*if (parse(argv[1]) == -1)
		return (-1);*/
	data.background = &b;
	data.player = &p;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "MAIN");
	b = init_background(&data, "../maps/small.ber");
	p = init_player(data);
	render_frame(&data);
	mlx_hook(data.win, 2, 1L<<0, handle_inputs, &data);
	mlx_loop(data.mlx);
	return (0);
}
