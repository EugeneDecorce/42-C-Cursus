/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:14:03 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/24 16:24:02 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_coord	gen_coordinates(int x, int y)
{
	t_coord	coordinates;

	coordinates.x = x;
	coordinates.y = y;
	return (coordinates);
}
