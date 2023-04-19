/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:43:47 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/19 19:22:02 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "libft/libft.h"
# include "../mlx_linux/minilibx-linux/mlx.h"

typedef struct	s_data
{
	void				*mlx;
	void				*win;
	t_background_img	*background;
	t_player			*player;
}	t_data;

typedef struct	s_background_img
{
	void	*wall;
	void	*coll;
	void	*empty;
	void	*exit;
	int		collected;
	char 	**map;
}	t_background_img;

typedef struct	s_player
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	int		x;
	int		y;
	char	ori;
	int		moves;
}	t_player;

void	init_background(t_data *data, char *map);
void	init_player(t_data *data);
void	render_frame(t_background_img background);
void	player_overlay(t_data *data);
int		handle_inputs(int key, t_data *data);
#endif
