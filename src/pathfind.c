/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:37:55 by liamv             #+#    #+#             */
/*   Updated: 2023/05/09 16:26:19 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_dfs_search(char **map, int x, int y, char to_find)
{
	int	temp;

	if (map[y][x] == '1')
		return (0);
	temp = 0;
	if (map[y][x] == to_find)
		temp++;
	map[y][x] = '1';
	temp += ft_dfs_search(map, x + 1, y, to_find);
	temp += ft_dfs_search(map, x - 1, y, to_find);
	temp += ft_dfs_search(map, x, y + 1, to_find);
	temp += ft_dfs_search(map, x, y - 1, to_find);
	return (temp);
}
