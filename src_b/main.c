/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:45:55 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/10 17:11:01 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_end(t_data *data)
{
	int	x;
	int	y;

	x = data->player->x;
	y = data->player->y;
	if (data->background->map[y][x] == 'E')
	{
		if (data->background->collected == data->background->coll_end)
		{
			end(data);
			exit(EXIT_SUCCESS);
		}
	}
	if (data->background->map[y][x] == 'X')
	{
		end(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int end_cross(t_data *data)
{
	end(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data				data;
	t_background_img	b;
	t_player			p;

	if (argc != 2)
		ft_error("Wrong command!\nCommand usage: ./so_long <map_path>");
	parse(argv[1]);
	data.player = &p;
	data.background = &b;
	data.mlx = mlx_init();
	init(&data, argv[1]);
	data.win = mlx_new_window(data.mlx, 673, 695, "YEAH BUDDY");
	game_loop(&data);
	mlx_expose_hook(data.win, &game_loop, &data);
	mlx_hook(data.win, 2, 1L << 0, handle_inputs, &data);
	mlx_loop_hook(data.mlx, &check_end, &data);
	mlx_hook(data.win, 17, 0, &end_cross, &data);
	mlx_loop(data.mlx);
	return (0);
}
