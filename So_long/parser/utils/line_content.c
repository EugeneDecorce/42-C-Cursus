/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:37:49 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/23 14:42:46 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_line_contain_invalid_character(char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P')
		{
			ft_putstr("Error\nThe map contain invalid character: ");
			ft_putchar(line[i]);
			ft_putstr("!\nOnly the following are allowed: 0 1 C E P");
			close(fd);
			exit(1);
		}
		i++;
	}
}

int	line_contain_only(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	line_head_tail_character(char *line, int c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((!line[i + 1] || i == 0) && line[i] != c)
			return (1);
		i++;
	}
	return (0);
}
