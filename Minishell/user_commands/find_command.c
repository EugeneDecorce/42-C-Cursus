/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:53:59 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/10 23:02:22 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	find_in_path_init(char **path, char **path_copy)
{
	*path = getenv("PATH");
	if (!(*path))
		return (1);
	*path_copy = ft_strdup(*path);
	if (!(*path_copy))
	{
		perror("minishell: strdup error");
		ft_cmd_status(1);
		exit(EXIT_FAILURE);
	}
	return (0);
}

char	*find_in_path(const char *command)
{
	char		*path;
	char		*path_copy;
	char		*dir;
	char		full_path[MAX_PATH_LENGTH];
	struct stat	buffer;

	if (find_in_path_init(&path, &path_copy))
		return (NULL);
	dir = ft_strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path[0] = '\0';
		if (ft_strlen(dir) + ft_strlen((char *)command) + 2 <= MAX_PATH_LENGTH)
		{
			printf("1");
			ft_strcpy(full_path, dir);
			ft_strcat(full_path, "/");
			ft_strcat(full_path, command);
			if (stat(full_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
				return (free(path_copy), ft_strdup(full_path));
		}
		dir = ft_strtok(NULL, ":");
	}
	printf("2");
	free(path_copy);
	return (NULL);
}
