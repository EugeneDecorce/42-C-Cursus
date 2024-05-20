/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:40:34 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/17 15:27:45 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
static char	*save_remainder(char *remainder)
{
	char	*newline_pos;
	char	*new_remainder;

	newline_pos = ft_strchr(remainder, '\n');
	if (!newline_pos)
		return (NULL);
	new_remainder = ft_substr(newline_pos + 1, 0, ft_strlen(newline_pos + 1));
	if (!new_remainder)
		return (NULL);
	*newline_pos = '\0';
	return (new_remainder);
}

static char	*read_to_remainder(int fd, char *remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;
		if (ft_strchr(remainder, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		free(remainder);
		return (NULL);
	}
	return (remainder);
}


char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*newline_pos;
	char		*line;
	char		*temp_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_to_remainder(fd, remainder);
	if (remainder == NULL)
		return (NULL);
	newline_pos = ft_strchr(remainder, '\n');
	if (newline_pos)
		line = ft_substr(remainder, 0, newline_pos - remainder + 1);
	else
		line = ft_strdup(remainder);
	temp_buffer = remainder;
	remainder = save_remainder(remainder);
	free(temp_buffer);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}


// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		int fd = open(argv[1], O_RDONLY);
// 		char *line = get_next_line(fd);
// 		printf("[%s]", line);
// 		line = get_next_line(fd);
// 		printf("[%s]", line);
// 	}
// 	return (0);
// }