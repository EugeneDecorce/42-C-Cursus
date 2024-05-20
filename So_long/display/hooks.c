/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:24:37 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/24 16:34:59 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_key_hook_param *params)
{
	t_coord	c;

	c = get_current_position(params->map, 'P');
	if (keycode == 65307)
	{
		free_map(params->map);
		exit(0);
	}
	is_valid_action(keycode == 119, params, gen_coordinates(c.x, c.y - 1));
	is_valid_action(keycode == 97, params, gen_coordinates(c.x - 1, c.y));
	is_valid_action(keycode == 115, params, gen_coordinates(c.x, c.y + 1));
	is_valid_action(keycode == 100, params, gen_coordinates(c.x + 1, c.y));
	return (0);
}

int	close_hook(t_key_hook_param *param)
{
	free_map(param->map);
	exit(0);
}
