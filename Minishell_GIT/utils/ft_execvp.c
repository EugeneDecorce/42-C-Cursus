/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execvp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:55:35 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 20:49:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

char	**process_argv(char *const argv[], int *len)
{
	char	**new_argv;
	int		i;

	i = 0;
	while (argv[i])
		i++;
	new_argv = malloc((i + 1) * sizeof(char *));
	if (new_argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[i])
	{
		new_argv[i] = remove_quotes(argv[i]);
		i++;
	}
	new_argv[i] = NULL;
	*len = i;
	return (new_argv);
}

int	fast_exec(char *file, char *const argv[])
{
	extern char	**environ;
	char		**new_argv;
	int			len;

	if (file && ft_strchr(file, '/'))
	{
		new_argv = process_argv(argv, &len);
		execve(file, new_argv, environ);
		ft_freemap(new_argv, len);
		return (-1);
	}
	return (0);
}

int	complete_exec(char *file, char *const argv[],
	char *path, char full_path[MAX_PATH_LENGTH])
{
	extern char	**environ;
	char		**new_argv;
	int			len;

	while (path != NULL)
	{
		if (file && ft_strlen(path) + 1 + ft_strlen(file) < MAX_PATH_LENGTH)
		{
			ft_strcpy(full_path, path);
			ft_strcat(full_path, "/");
			ft_strcat(full_path, file);
			if (access(full_path, X_OK) == 0)
			{
				new_argv = process_argv(argv, &len);
				execve(full_path, new_argv, environ);
				ft_freemap(new_argv, len);
				return (-1);
			}
		}
		path = ft_strtok(NULL, ":");
	}
	return (0);
}

int	ft_execvp(char *file, char *const argv[])
{
	extern char	**environ;
	char		full_path[MAX_PATH_LENGTH];
	char		*path_env;
	char		*path_env_dup;
	char		*path;

	if (fast_exec(file, argv) == -1)
		return (-1);
	path_env = getenv("PATH");
	if (!path_env)
	{
		perror("getenv");
		return (-1);
	}
	path_env_dup = ft_strdup(path_env);
	if (!path_env_dup)
	{
		perror("strdup");
		return (-1);
	}
	path = ft_strtok(path_env_dup, ":");
	if (complete_exec(file, argv, path, full_path) == -1)
		return (free(path_env_dup), -1);
	free(path_env_dup);
	return (-1);
}
