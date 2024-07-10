/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_with_pipes_helper.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:29:08 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/09 16:51:00 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	wait_for_all_commands(int num_commands)
{
	int	status;
	int	i;

	i = 0;
	while (i < num_commands)
	{
		wait(&status);
		i++;
	}
	return (0);
}

int	execute_command(char **args)
{
	char	*command_path;

	command_path = get_command_path(args[0]);
	if (command_path != NULL)
	{
		execv(command_path, args);
		perror("minishell: exec error");
		free(command_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("minishell: %s: command not found\n", args[0]);
		ft_cmd_status(127);
		return (0);
	}
	return (1);
}

int	create_pipe(int pipe_fds[2])
{
	if (pipe(pipe_fds) == -1)
	{
		perror("minishell: pipe error");
		return (1);
	}
	return (0);
}

int	update_input_fd(int in_fd, int i, int num_commands, int pipe_fds[2])
{
	if (in_fd != STDIN_FILENO)
		close(in_fd);
	if (i < num_commands - 1)
	{
		close(pipe_fds[1]);
		in_fd = pipe_fds[0];
	}
	return (in_fd);
}
