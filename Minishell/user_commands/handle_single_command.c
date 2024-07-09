/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_single_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:44:57 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/08 19:51:38 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	single_command_wait_pid(pid_t pid)
{
	int		status;

	while (waitpid(pid, &status, WUNTRACED) != -1)
	{
		if (WIFEXITED(status) || WIFSIGNALED(status))
			break ;
	}
}

void	fd_management(int out_fds[MAX_ARGS],
	int num_out_fds, char *command_path, char **args)
{
	int	i;

	i = 0;
	if (num_out_fds > 0)
	{
		while (i < num_out_fds)
		{
			dup2(out_fds[i], STDOUT_FILENO);
			close(out_fds[i]);
		}
	}
	execv(command_path, args);
	perror("exec error");
	exit(EXIT_FAILURE);
}

void	close_fds(int num_out_fds, int out_fds[MAX_ARGS])
{
	int	i;

	i = 0;
	while (i < num_out_fds)
	{
		close(out_fds[i]);
		i++;
	}
}

int	single_command_helper(char ***args, char *input,
	int *in_fd, char **command_path)
{
	*args = parse_user_input(input);
	*in_fd = process_input_redirection(*args, input);
	if (*in_fd == -1 && args[0] == NULL)
		return (free(*args), 1);
	if (handle_single_command_logic(command_path, *args))
		return (free(*args), 1);
	return (0);
}

// in_fd = -1, result = 0
int	handle_single_command(char *input, int result, int in_fd)
{
	char	*command_path;
	char	**args;
	int		num_out_fds;
	int		out_fds[MAX_ARGS];
	pid_t	pid;

	if (single_command_helper(&args, input, &in_fd, &command_path))
		return (1);
	if (process_output_redirection(args, out_fds, &num_out_fds) == -1)
		return (free(args), 1);
	pid = fork();
	if (pid == 0)
	{
		if (in_fd != -1)
			dup2(in_fd, STDIN_FILENO);
		if (in_fd != -1)
			close(in_fd);
		fd_management(out_fds, num_out_fds, command_path, args);
	}
	else if (pid < 0)
		result = 1;
	else
		single_command_wait_pid(pid);
	close_fds(num_out_fds, out_fds);
	return (free(command_path), free(args), result);
}
