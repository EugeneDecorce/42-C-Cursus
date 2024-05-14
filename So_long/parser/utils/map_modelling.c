/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modelling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:29:58 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/24 11:06:32 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	create_map(char ***map, int row, int *col, char *file)
{
	int		fd;
	char	*line;
	int		i;

	*map = (char **) malloc((row + 1) * sizeof(char *));
	if (*map == NULL)
		exit(1);
	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	(*col) = ft_strlen(line);
	while (line != NULL)
	{
		(*map)[i] = ft_strdup(line);
		if ((*map)[i] == NULL)
		{
			free_map(*map);
			exit(1);
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	(*map)[i] = NULL;
	close(fd);
}

void	duplicate_map(char **map, char ***map_copy)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	*map_copy = (char **) malloc((i + 1) * sizeof(char *));
	if (*map_copy == NULL)
	{
		free_map(map);
		exit(1);
	}
	i = 0;
	while (map[i])
	{
		(*map_copy)[i] = ft_strdup(map[i]);
		if ((*map_copy)[i] == NULL)
		{
			free_map(map);
			free_map(*map_copy);
			exit(1);
		}
		i++;
	}
	(*map_copy)[i] = NULL;
}
