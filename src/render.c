/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:11:35 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/09 16:32:55 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_lst_len(char **lst)
{
	int	i;

	i = -1;
	while (lst[++i])
		;
	return (i);
}

static void	choice_bground(t_data *data, int x, int y)
{
	t_background_img	*b;
	int					crd[2];
	char				c;
	void				*mlx;

	b = data->background;
	mlx = data->mlx;
	crd[0] = data->player->y - 10 + y;
	crd[1] = data->player->x - 10 + x;
	if (crd[0] < 0 || crd[1] < 0)
		return ;
	if (crd[0] >= ft_lst_len(b->map))
		return ;
	if ((size_t)crd[1] >= ft_strlen(b->map[crd[0]]))
		return ;
	c = b->map[crd[0]][crd[1]];
	if (c == '0' || c == 'P')
		mlx_put_image_to_window(mlx, data->win, b->empty, x * 32, y * 32);
	else if (c == '1')
		mlx_put_image_to_window(mlx, data->win, b->wall, x * 32, y * 32);
	else if (c == 'C')
		mlx_put_image_to_window(mlx, data->win, b->coll, x * 32, y * 32);
	else if (c == 'E')
		mlx_put_image_to_window(mlx, data->win, b->exit, x * 32, y * 32);
}

static void	render_frame(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y <= 20)
	{
		x = -1;
		while (++x <= 20)
			choice_bground(data, x, y);
	}
}

int	game_loop(t_data *data)
{
	t_player	*p;

	p = data->player;
	mlx_clear_window(data->mlx, data->win);
	render_frame(data);
	mlx_put_image_to_window(data->mlx, data->win, p->sprite, 320, 320);
	return (0);
}
