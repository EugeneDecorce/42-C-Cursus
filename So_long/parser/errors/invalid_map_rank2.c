/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map_rank2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:32:23 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/23 15:09:12 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	is_map_external_wall_invalid(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
	{
		ft_putstr("Error\nError occurred during map creation: ");
		ft_putstr("<memory allocation failed>\n");
		exit(1);
	}
	while (map[i])
	{
		if (((map[i + 1] == NULL || i == 0) && !line_contain_only(map[i], '1'))
			|| line_head_tail_character(map[i], '1'))
		{
			ft_putstr("Error\nYour map wall is incomplete. ");
			ft_putstr("You need to embed your map with 1s!\n");
			free_map(map);
			exit(1);
		}
		i++;
	}
}

int	testing_all_possible_paths(char **map, int y, int x, char target)
{
	if (map[y][x] == target && target == 'E')
		return (0);
	if (map[y][x] == 'C' || map[y][x] == '0' || map[y][x] == 'P')
	{
		map[y][x] = '*';
		if (!testing_all_possible_paths(map, y - 1, x, target)
			|| !testing_all_possible_paths(map, y, x - 1, target)
			|| !testing_all_possible_paths(map, y, x + 1, target)
			|| !testing_all_possible_paths(map, y + 1, x, target))
			return (0);
	}
	return (1);
}

int	is_map_not_feasable(char **map, char target)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (testing_all_possible_paths(map, i, j, target));
			j++;
		}
		i++;
	}
	return (1);
}

int	all_collectibles_not_reachable(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_invalid_map_rank2(char **map)
{
	char	**map_copy;

	is_map_external_wall_invalid(map);
	duplicate_map(map, &map_copy);
	if (is_map_not_feasable(map_copy, 'E'))
	{
		ft_putstr("Error\nYour map is not feasable. Ensure there is at ");
		ft_putstr("least one path that leads to the exit point (E).\n");
		free_map(map);
		free_map(map_copy);
		exit(1);
	}
	free_map(map_copy);
	duplicate_map(map, &map_copy);
	is_map_not_feasable(map_copy, 'C');
	if (all_collectibles_not_reachable(map_copy))
	{
		ft_putstr("Error\nAt least one collectible is not reachable. Ensure ");
		ft_putstr("there is at least one path that leads ");
		ft_putstr("to all collectibles (C).\n");
		free_map(map);
		free_map(map_copy);
		exit(1);
	}
	free_map(map_copy);
}
