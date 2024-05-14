/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:15:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/24 16:25:50 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		row;
	int		col;

	check_args_count(argc);
	row = 0;
	check_invalid_map_rank1(argv[1], &row);
	create_map(&map, row, &col, argv[1]);
	check_invalid_map_rank2(map);
	display(map, row, col);
	free_map(map);
	return (0);
}
