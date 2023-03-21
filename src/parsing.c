/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:49:54 by lvincent          #+#    #+#             */
/*   Updated: 2023/03/21 13:55:52 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int not_rectangle(char *map)
{
	char *line;
	int len;
	int size;

	line = get_next_line(map);
	while (line)
	{
		if (ft_strlen(line) != len)
			return (-1);
		free(line);
		line = get_next_line(map);
		size++;
	}
	return (size);
}

int parse(char *to_parse)
{
	if (ft_strncmp(ft_strchr(to_parse, '.'), ".ber", 4))
	{
		ft_printf("Error!\n Wrong file extension\n");
		return (-1);
	}
	if (not_rectangle(to_parse) == -1)
	{
		ft_printf("Error!\n Map is not rectangular\n");
		return (-1);
	}
	if (map_elements(to_parse))
	{
	}
	return (0);
}