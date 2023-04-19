/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:43:47 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/19 18:02:42 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "libft/libft.h"
# include "../mlx_linux/minilibx-linux/mlx.h"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
}	t_data;

typedef struct	s_background_img
{
	void	*wall;
	void	*coll;
	void	*empty;
	void	*exit;
	int		collected;
	char 	**map;
	t_data	data;
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
	t_data	data;
}	t_player;


int		parse(char *to_parse);
void	init_background(t_background_img *back, t_data main, char *map);
void	init_player(t_player *player, t_data main, char **map);
void	render_frame(t_background_img background);
void	player_overlay(t_player *player, t_background_img map);
int		handle_no_event(void *data);
int		handle_inputs(int key, t_data *data);
#endif
