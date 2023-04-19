/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:45:55 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/19 18:23:28 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	
	t_background_img	background;
	t_player			player;
	t_data				main;
	
	/*if (parse(argv[1]) == -1)
		return (-1);*/
	main.mlx = mlx_init();
	main.win = mlx_new_window(main.mlx, 1920, 1080, "MAIN");
	init_background(&background, main, argv[1]);
	init_player(&player, main, background.map);
	render_frame(background);
	mlx_hook(main.win, 2, 1L<<0, handle_inputs, &main);
	mlx_loop(main.mlx);
	return (0);
}