/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:45:55 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/19 19:24:47 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data				data;
	
	/*if (parse(argv[1]) == -1)
		return (-1);*/
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "MAIN");
	init_background(&data, argv[1]);
	init_player(&data);
	render_frame(background);
	mlx_hook(main.win, 2, 1L<<0, handle_inputs, &main);
	mlx_loop(main.mlx);
	return (0);
}