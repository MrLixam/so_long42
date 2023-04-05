/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:45:55 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/05 15:41:56 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	
	t_background_img	background;
	t_player			player;
	void				*mlx;
	void				*win;
	
	/*if (parse(argv[1]) == -1)
		return (-1);*/
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "MAIN");
	init_background(&background, mlx, win, argv[1]);
	init_player(&player, mlx, background.map);
	mlx_loop(mlx);
	return (0);
}