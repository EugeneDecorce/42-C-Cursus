/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:46:47 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/10 19:25:08 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	pipe_commands_management(char ***args, char ***cmd_end,
	pid_t *pid, int pipefd[2])
{
	int	i;

	i = 0;
	while ((*args)[i] != NULL && ft_strcmp((*args)[i], "|") != 0)
		i++;
	*cmd_end = &(*args)[i];
	if (*(*cmd_end) != NULL)
	{
		*(*cmd_end) = NULL;
		(*cmd_end)++;
	}
	if (*(*cmd_end) != NULL && pipe(pipefd) == -1)
	{
		perror("pipe");
		ft_cmd_status(127);
		exit(EXIT_FAILURE);
	}
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		ft_cmd_status(127);
		exit(EXIT_FAILURE);
	}
}

void	pipe_null_pid_management(int in_fd, int pipefd[2],
	char **cmd_start, char **cmd_end)
{
	if (in_fd != STDIN_FILENO)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (*(cmd_end) != NULL)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
	}
	handle_redirections(cmd_start);
	ft_cmd_status(execve(cmd_start[0], cmd_start, (char * const *)getenv("PATH")));
	perror("execve error");
	ft_cmd_status(127);
	exit(EXIT_FAILURE);
}

void	execute_pipe(char **args)
{
	int		pipefd[2];
	int		in_fd;
	pid_t	pid;
	char	**cmd_start;
	char	**cmd_end;

	in_fd = STDIN_FILENO;
	cmd_start = args;
	while (*args)
	{
		pipe_commands_management(&args, &cmd_end, &pid, pipefd);
		if (pid == 0)
			pipe_null_pid_management(in_fd, pipefd, cmd_start, cmd_end);
		else
		{
			if (pipefd[1] != -1)
				close(pipefd[1]);
			if (in_fd != STDIN_FILENO)
				close(in_fd);
			in_fd = pipefd[0];
			cmd_start = cmd_end;
			args = cmd_end;
		}
	}
	while (wait(NULL) > 0);
}

void	exec_pipes(int pipe_found, char **args)
{
	int		status;
	pid_t	pid;

	if (pipe_found)
	{
		execute_pipe(args);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			ft_cmd_status(127);
			handle_redirections(args);
			execvp(args[0], args);
			printf("%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			perror("fork");
		else
			waitpid(pid, &status, 0);
	}
}

void	exec_command(char *input)
{
	char	**args;
	int		pipe_found;
	int		i;

	pipe_found = 0;
	args = parse_user_input(input);
	if (args[0] == NULL)
		return ;
	i = 0;
	while (args[i] != NULL)
	{
		if (strcmp(args[i], "|") == 0)
		{
			pipe_found = 1;
			break ;
		}
		i++;
	}
	exec_pipes(pipe_found, args);
	free(args);
}
