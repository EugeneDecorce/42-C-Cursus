/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:06:51 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/14 09:50:07 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

int	open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putstr("Cannot read file.");
	return (fd);
}

void	read_file(int fd)
{
	char	buffer[501];
	int		bytes_read;

	bytes_read = read(fd, buffer, 500);
	if (bytes_read <= 0)
		return ;
	buffer[bytes_read] = '\0';
	ft_putstr(buffer);
	read_file(fd);
}

// if (bytes_read <= 0)
	// 	return ;
	// ft_putstr(buffer);

void	display_file(char *file)
{
	int		fd;

	fd = open_file(file);
	if (fd == -1)
		return ;
	read_file(fd);
}


int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("File name missing.");
	else if (argc > 2)
		ft_putstr("Too many arguments.");
	else
		display_file(argv[1]);
	return (0);
}