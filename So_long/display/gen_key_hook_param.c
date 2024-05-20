/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_key_hook_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:18:42 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/24 16:33:34 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_key_hook_param	gen_key_hook_param(void *mlx, void *w, char **map, int *t)
{
	t_key_hook_param	params;

	params.mlx = mlx;
	params.mlx_win = w;
	params.map = map;
	params.total = t;
	return (params);
}
