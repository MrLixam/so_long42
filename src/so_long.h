/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:43:47 by lvincent          #+#    #+#             */
/*   Updated: 2023/03/21 17:08:47 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "libft/libft.h"
# include "../mlx_linux/minilibx-linux/mlx.h"

typedef struct	s_background_img
{
	void	*wall;
	void	*coll;
	void	*empty;
	void	*exit;
	void	*win;
	void	*mlx;
}	t_background_img;

typedef struct	s_player_sprite
{
	void *img_north;
	void *img_south;
	void *img_west;
	void *img_east;
}	t_player_sprite;


int	parse(char *to_parse);
#endif