/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:45:55 by lvincent          #+#    #+#             */
/*   Updated: 2023/03/21 17:23:04 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_background(t_background_img *back, void *mlx, void *win)
{
	int	w;
	int	h;

	h = 32;
	w = 32;
	back->wall = mlx_xpm_file_to_image(mlx, "../res/rock.xpm", &w, &h);
	back->empty = mlx_xpm_file_to_image(mlx, "../res/grass.xpm", &w, &h);
	back->coll = mlx_xpm_file_to_image(mlx, "../res/tacos.xpm", &w, &h);
	back->exit = mlx_xpm_file_to_image(mlx, "../res/sombrero.xpm", &w, &h);
	back->mlx = mlx;
	back->win = win;
}

int main(int argc, char **argv)
{
	t_background_img	background;
	void				*mlx;
	void				*win;
	
	if (parse(argv[1]) == -1)
		return (-1);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "MAIN");
	init_background(&background, mlx, win);
	background_render(argv[1], background);
	return (0);
}