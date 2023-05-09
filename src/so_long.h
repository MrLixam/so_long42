/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:43:47 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/09 16:40:53 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_background_img
{
	void	*wall;
	void	*coll;
	void	*empty;
	void	*exit;
	int		collected;
	int		coll_end;
	char	**map;
}	t_background_img;

typedef struct s_player
{
	void	*sprite;
	int		x;
	int		y;
	int		moves;
}	t_player;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	t_background_img	*background;
	t_player			*player;
}	t_data;

void		init(t_data *data, char *map);
int			handle_inputs(int key, t_data *data);
int			game_loop(t_data *data);
void		ft_error(char *err_mes);
char		**map_to_list(char *map);
void		end(t_data *data);
void		parse(char *to_parse);
void		free_map(char **map);
int			ft_dfs_search(char **map, int x, int y, char to_find);
void		parse3(char *to_parse);

#endif
