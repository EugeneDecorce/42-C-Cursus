/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_with_pipes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:29:02 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/09 22:41:48 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int check_commands_in_path(char **commands)
{
	char	*command;
	char	*command_path;
	int		i;

	i = 0;
	while (commands[i])
	{
		command = ft_strtrim(commands[i]);
		if (command == NULL)
			return (0);
		command_path = find_in_path(command);
		free(command);
		if (command_path == NULL)
		{
			printf("minishell: %s: command not found\n", commands[i]);
			ft_cmd_status(127);
			return (0);
		}
		free(command_path);
		i++;
	}
	return (1);
}

int	exec_command_with_pipes(char *input, int i)
{
	char	**args;
	char	*commands[MAX_ARGS];
	int		num_commands;
	int		in_fd;

	num_commands = split_commands(&in_fd, input, commands);
	while (i < num_commands)
	{
		args = parse_user_input(commands[i]);
		if (!check_commands_in_path(commands))
			return (free(args), 1);
		if (pipes_flow(i, &args, num_commands, &in_fd))
		{
			wait_for_all_commands(num_commands);
			return (free(args), 1);
		}
		free(args);
		i++;
	}
	return (wait_for_all_commands(num_commands));
}

int	pipes_flow(int i, char ***args, int num_commands, int *in_fd)
{
	int		out_fds[MAX_ARGS];
	int		num_out_fds;
	int		pipe_fds[2];
	pid_t	pid;

	pipes_flow_helper0(out_fds);
	if (i < num_commands - 1 && create_pipe(pipe_fds) != 0)
		return (1);
	num_out_fds = 0;
	if (process_output_redirection(*args, out_fds, &num_out_fds) == -1)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		pipes_flow_helper1(i, &in_fd, num_commands, pipe_fds);
		pipes_flow_helper2(num_out_fds, out_fds);
		execute_command(*args);
	}
	else if (pid < 0)
		return (1);
	*in_fd = update_input_fd(*in_fd, i, num_commands, pipe_fds);
	pipes_flow_helper3(num_out_fds, out_fds);
	return (0);
}
