#include "../../main/minishell.h"

void	absolute_path(char **path, char *cmd, t_utils *data);

int	check_command(char **path, t_utils *data, char *cmd)
{
	if (!ft_strchr(cmd, '/'))
		*path = find_command(data, cmd, data->env);
	else
		absolute_path(path, cmd, data);
	if (!(*path) && data->exit_code == -1)
		free_data(data, NULL, data->exit_code);
	if (!(*path))
	{
		data->exit_code = 127;
		return (0);
	}
	return (1);
}

void	absolute_path(char **path, char *cmd, t_utils *data)
{
	*path = ft_strdup(cmd);
	if (!(*path))
		free_data(data, "malloc error\n", 1);
	if (access((*path), F_OK))
	{
		write(2, (*path), ft_strlen((*path)));
		write(2, " : command not found\n", 21);
		free(*path);
		*path = NULL;
	}
}

int	check_command_viability(char **path, t_utils *data, char *cmd)
{
	if (!check_command(path, data, cmd))
		return (0);
	if (access((*path), X_OK))
	{
		printf(*path);
		free((*path));
		(*path) = NULL;
		data->exit_code = 126;
		return (0);
	}
	if (!check_dir(path, cmd, data))
		return (0);
	return (1);
}

char	*command_not_found(char *sample)
{
	write(2, sample, ft_strlen(sample));
	write(2, " : command not found\n", 21);
	return (NULL);
}

char	*find_command(t_utils *data, char *sample, t_list *env)
{
	char		*paths;
	char		path[PATH_MAX];
	int			i;
	int			len;

	paths = create_paths(env, ft_lstsize(env));
	if (!paths || ft_strlen(sample) > PATH_MAX / 2)
		return (command_not_found(sample));
	i = 0;
	len = ft_strlen(paths);
	while (i < len)
	{
		recreate_path(path, sample, paths, &i);
		if (access(path, F_OK) == 0)
		{
			sample = ft_strdup(path);
			if (!sample)
			{
				printf("malloc error\n");
				data->exit_code = -1;
			}
			return (sample);
		}
	}
	return (command_not_found(sample));
}
