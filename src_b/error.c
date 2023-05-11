/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:18:55 by liamv             #+#    #+#             */
/*   Updated: 2023/05/10 16:03:24 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *err_mes)
{
	ft_printf("Error!\n");
	ft_printf("%s\n", err_mes);
	exit(EXIT_FAILURE);
}

static void	end_player(t_player *p, void *mlx)
{
	if (p->west)
		mlx_destroy_image(mlx, p->west);
	if (p->east)
		mlx_destroy_image(mlx, p->east);
	if (p->south)
		mlx_destroy_image(mlx, p->south);
	if (p->south)
		mlx_destroy_image(mlx, p->north);
}

static void	end_background(t_background_img *b, void *mlx)
{
	if (b->empty)
		mlx_destroy_image(mlx, b->empty);
	if (b->wall)
		mlx_destroy_image(mlx, b->wall);
	if (b->coll)
		mlx_destroy_image(mlx, b->coll);
	if (b->exit)
		mlx_destroy_image(mlx, b->exit);
	if (b->patr)
		mlx_destroy_image(mlx, b->patr);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	end(t_data *data)
{
	void	*mlx;

	if (data->mlx)
	{
		mlx = data->mlx;
		mlx_loop_end(mlx);
		if (data->win)
			mlx_destroy_window(mlx, data->win);
		if (data->player)
			end_player(data->player, mlx);
		if (data->background)
			end_background(data->background, mlx);
		mlx_destroy_display(mlx);
		free(mlx);
	}
	if (data->background)
		if (data->background->map)
			free_map(data->background->map);
}
