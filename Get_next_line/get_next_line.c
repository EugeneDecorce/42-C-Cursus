/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:13:44 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/23 13:17:12 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	initialize(int fd, int *i, char **buffer)
{
	int			bytes_read;

	*i = 0;
	*buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (0);
	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (0);
	return (1);
}

char	*handle_last_line(int bytes_read, char **buffer, int *i)
{
	char		*last_line;

	if (bytes_read == 0 && ft_strlen(*buffer))
	{
		last_line = extract_line(*buffer, *i, i);
		free(*buffer);
		*buffer = NULL;
		return (last_line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static int	i;
	static char	*buffer;
	char		buffer2[BUFFER_SIZE + 1];
	char		*tmp_buffer;
	int			bytes_read;

	if (!buffer && !initialize(fd, &i, &buffer))
		return (NULL);
	while (get_next_return_index(buffer, i) == -1)
	{
		bytes_read = read(fd, buffer2, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (handle_last_line(bytes_read, &buffer, &i));
		buffer2[bytes_read] = '\0';
		tmp_buffer = ft_strdup(buffer);
		if (tmp_buffer == NULL)
			return (NULL);
		free(buffer);
		buffer = ft_strjoin(tmp_buffer, buffer2);
		free(tmp_buffer);
		if (buffer == NULL)
			return (NULL);
	}
	return (extract_line(buffer, i, &i));
}

#include <stdio.h>
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (1);
		char *line;
		line = get_next_line(fd);
		while (line != NULL)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
	}
	return (0);
}*/