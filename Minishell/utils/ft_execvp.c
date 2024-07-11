/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execvp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:55:35 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/10 23:01:28 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	ft_execvp(const char *file, char *const argv[])
{
	extern char	**environ;
	char		full_path[MAX_PATH_LENGTH];
	char		*path_env;
	char		*path_env_dup;
	char		*path;

	if (ft_strchr(file, '/'))
		return execve(file, argv, environ);
	path_env = getenv("PATH");
	if (!path_env)
	{
		perror("getenv");
		return -1;
	}
	path_env_dup = ft_strdup(path_env);
	if (!path_env_dup)
	{
		perror("strdup");
		return -1;
	}
	path = ft_strtok(path_env_dup, ":");
	while (path != NULL)
	{
		if (ft_strlen((char *)path) + 1 + ft_strlen((char *)file) < MAX_PATH_LENGTH)
		{
			ft_strcpy(full_path, path);
			ft_strcat(full_path, "/");
			ft_strcat(full_path, file);
			if (access(full_path, X_OK) == 0)
			{
				execve(full_path, argv, environ);
				perror("execve");
				free(path_env_dup);
				return -1;
			}
		}
		path = ft_strtok(NULL, ":");
	}
	free(path_env_dup);
	return -1;
}
