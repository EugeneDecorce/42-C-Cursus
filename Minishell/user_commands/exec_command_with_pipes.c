/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_with_pipes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:29:02 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/08 20:11:34 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

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
		if (helper(i, &args, num_commands, &in_fd))
			return (1);
		free(args);
		i++;
	}
	return (wait_for_all_commands(num_commands));
}

int	helper(int i, char ***args, int num_commands, int *in_fd)
{
	int		out_fds[MAX_ARGS];
	int		num_out_fds;
	int		pipe_fds[2];
	pid_t	pid;

	init_out_fds(out_fds);
	if (i < num_commands - 1 && create_pipe(pipe_fds) != 0)
		return (1);
	num_out_fds = 0;
	if (process_output_redirection(*args, out_fds, &num_out_fds) == -1)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		helper_helper(i, &in_fd, num_commands, pipe_fds);
		helper_dup2_loop(num_out_fds, out_fds);
		execute_command(*args);
	}
	else if (pid < 0)
		return (1);
	*in_fd = update_input_fd(*in_fd, i, num_commands, pipe_fds);
	helper_close_loop(num_out_fds, out_fds);
	return (0);
}
