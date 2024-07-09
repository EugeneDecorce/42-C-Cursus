/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_user_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:27:55 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/09 06:27:21 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

char	*get_command_path(const char *command)
{
	struct stat	buffer;
	char		*command_path;

	if (command[0] == '/' || ft_strchr(command, '/'))
	{
		command_path = strdup(command);
		if (stat(command_path, &buffer) != 0 || !(buffer.st_mode & S_IXUSR))
		{
			free(command_path);
			return (NULL);
		}
		return (command_path);
	}
	return (find_user_command(command));
}

char	*find_absolute_command(const char *command)
{
	struct stat	buffer;

	if (stat(command, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		return (ft_strdup(command));
	return (NULL);
}

int	find_in_path_init(char **path, char **path_copy)
{
	*path = getenv("PATH");
	if (!(*path))
		return (1);
	*path_copy = ft_strdup(*path);
	if (!(*path_copy))
	{
		perror("minishell: strdup error");
		exit(EXIT_FAILURE);
	}
	return (0);
}

// char	*find_in_path(const char *command)
// {
// 	char		*path;
// 	char		*path_copy;
// 	char		*dir;
// 	char		full_path[MAX_PATH_LENGTH];
// 	struct stat	buffer;

// 	if (find_in_path_init(&path, &path_copy))
// 		return (NULL);
// 	dir = ft_strtok(path_copy, ":");
// 	while (dir != NULL)
// 	{
// 		ft_snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
// 		if (stat(full_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
// 		{
// 			free(path_copy);
// 			return (ft_strdup(full_path));
// 		}
// 		dir = ft_strtok(NULL, ":");
// 	}
// 	free(path_copy);
// 	return (NULL);
// }

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
			ft_strcpy(full_path, dir);
			ft_strcat(full_path, "/");
			ft_strcat(full_path, command);
			if (stat(full_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
				return (free(path_copy), ft_strdup(full_path));
		}
		dir = ft_strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

char	*find_user_command(const char *command)
{
	char	*command_path;

	command_path = find_absolute_command(command);
	if (command_path != NULL)
		return (command_path);
	command_path = find_in_path(command);
	if (command_path != NULL)
		return (command_path);
	return (NULL);
}
