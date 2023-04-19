/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:08:02 by lvincent          #+#    #+#             */
/*   Updated: 2023/04/19 19:01:49 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "keycodes.h"

int	handle_inputs(int key, t_data *data)
{
	if (key == K_ESC)
		end(data)
	if (key == K_A || key == K_D)
		move_player(key);
	return (0);
}