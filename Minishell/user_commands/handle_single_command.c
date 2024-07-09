/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_single_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:44:57 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/09 17:07:29 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	wait_pid(pid_t pid)
{
	int	status;

	while (waitpid(pid, &status, WUNTRACED) != -1)
	{
		if (WIFEXITED(status) || WIFSIGNALED(status))
			break ;
	}
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

int	single_commad_init(char ***args, char *input,
	int *in_fd, char **command_path)
{
	*args = parse_user_input(input);
	*in_fd = process_input_redirection(*args, input);
	if (*in_fd == -1 && args[0] == NULL)
		return (0);
	if (handle_single_command_logic(command_path, *args))
		return (0);
	return (1);
}

void	handle_null_pid(int *in_fd, int num_out_fds, int out_fds[MAX_ARGS])
{
	int	i;

	if (*in_fd != -1)
	{
		dup2(*in_fd, STDIN_FILENO);
		close(*in_fd);
	}
	if (num_out_fds > 0)
	{
		i = 0;
		while (i < num_out_fds)
		{
			dup2(out_fds[i], STDOUT_FILENO);
			close(out_fds[i]);
			i++;
		}
	}
}

// result = 0, in_fd = -1
int	handle_single_command(char *input, int result, int in_fd)
{
	char	*command_path;
	char	**args;
	int		out_fds[MAX_ARGS];
	int		num_out_fds;
	pid_t	pid;

	num_out_fds = 0;
	if (single_commad_init(&args, input, &in_fd, &command_path))
	{
		if (process_output_redirection(args, out_fds, &num_out_fds) == -1)
			return (free(args), 1);
		pid = fork();
		if (pid == 0)
		{
			handle_null_pid(&in_fd, num_out_fds, out_fds);
			execv(command_path, args);
			perror("exec error in minishell");
			free(command_path);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			result = 1;
		else
			wait_pid(pid);
		close_fds(num_out_fds, out_fds);
	}
	return (free(command_path), free(args), result);
}
