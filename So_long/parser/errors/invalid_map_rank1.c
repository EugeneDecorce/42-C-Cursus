/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map_rank1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:11:35 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/23 14:43:58 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_line_length(int fd, int *row, int *line_length, char *line)
{
	(*row)++;
	if (*line_length == -1)
		*line_length = ft_strlen(line);
	else if (*line_length != ft_strlen(line))
	{
		ft_putstr("Error\nThe map is not a rectangle!\n");
		close(fd);
		exit(1);
	}
}

void	check_too_much_elements(int fd, int e_count, int p_count)
{
	if (e_count > 1)
	{
		ft_putstr("Error\nThe map contain too many exits. ");
		ft_putstr("It should contain strictly one exit point!\n");
		ft_putstr("Only this is considered as an exit point: E\n");
		close(fd);
		exit(1);
	}
	if (p_count > 1)
	{
		ft_putstr("Error\nThe map contain too many positions. ");
		ft_putstr("It should contain strictly one position point!\n");
		ft_putstr("Only this is considered as a position point: P\n");
		close(fd);
		exit(1);
	}
}

void	check_not_enough_element(int c_count, int e_count, int p_count)
{
	if (c_count == 0)
	{
		ft_putstr("Error\nThe map does not contain any collectible. ");
		ft_putstr("It should contain at least one collectible!\n");
		ft_putstr("Only this is considered as a collectible: C\n");
		exit(1);
	}
	if (e_count == 0)
	{
		ft_putstr("Error\nThe map does not contain an exit. ");
		ft_putstr("It should contain strictly one exit point!\n");
		ft_putstr("Only this is considered as an exit point: E\n");
		exit(1);
	}
	if (p_count == 0)
	{
		ft_putstr("Error\nThe map does not contain a position. ");
		ft_putstr("It should contain strictly one position point!\n");
		ft_putstr("Only this is considered as a position point: P\n");
		exit(1);
	}
}

void	invalid_map(int fd, int *row)
{
	char	*line;
	int		line_length;
	int		c_count;
	int		e_count;
	int		p_count;

	c_count = 0;
	e_count = 0;
	p_count = 0;
	line_length = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		check_line_length(fd, row, &line_length, line);
		check_line_contain_invalid_character(line, fd);
		c_count += ft_strcountchar(line, 'C');
		e_count += ft_strcountchar(line, 'E');
		p_count += ft_strcountchar(line, 'P');
		check_too_much_elements(fd, e_count, p_count);
		free(line);
		line = get_next_line(fd);
	}
	check_not_enough_element(c_count, e_count, p_count);
}

void	check_invalid_map_rank1(char *map, int *row)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nError openning the file: ");
		exit(1);
	}
	invalid_map(fd, row);
	close(fd);
}
