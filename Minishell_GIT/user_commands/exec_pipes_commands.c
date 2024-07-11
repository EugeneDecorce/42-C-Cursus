/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:35:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 17:44:35 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	execute_pipe_wait(void)
{
	while (wait(NULL) > 0)
		;
}

void	pipe_commands_management(t_util *var, char ***cmd_end,
	pid_t *pid)
{
	int	i;

	i = 0;
	while ((var->args)[i] != NULL && ft_strcmp((var->args)[i], "|") != 0)
		i++;
	*cmd_end = &(var->args)[i];
	if (*(*cmd_end) != NULL)
	{
		*(*cmd_end) = NULL;
		(*cmd_end)++;
	}
	pipe(var->pipefd);
	if (*(*cmd_end) != NULL && pipe(var->pipefd) == -1)
	{
		perror("pipe");
		ft_cmd_status(127);
		ft_freemap(var->args);
		free(var->input);
		ft_freemap(var->result);
		exit(EXIT_FAILURE);
	}
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		ft_cmd_status(127);
		free(var->input);
		ft_freemap(var->args);
		ft_freemap(var->result);
		exit(EXIT_FAILURE);
	}
}

void	pipe_null_pid_management(int in_fd, t_util *var,
	char **cmd_start, char **cmd_end)
{
	if (in_fd != STDIN_FILENO)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (*(cmd_end) != NULL)
	{
		dup2(var->pipefd[1], STDOUT_FILENO);
		close(var->pipefd[0]);
		close(var->pipefd[1]);
	}
	handle_redirections(var);
	ft_execvp(cmd_start[0], cmd_start);
	perror("exeve error");
	ft_cmd_status(127);
	free(var->input) ;
	ft_freemap(var->result);
	ft_freemap(var->args);
	exit(EXIT_FAILURE);
}

void	execute_pipe(t_util *var)
{
	int		in_fd;
	pid_t	pid;
	char	**cmd_start;
	char	**cmd_end;

	in_fd = STDIN_FILENO;
	cmd_start = var->args; 
	while (*var->args)
	{
		pipe_commands_management(var, &cmd_end, &pid);
		if (pid == 0)
			pipe_null_pid_management(in_fd, var, cmd_start, cmd_end);
		else
		{
			if (var->pipefd[1] != -1)
				close(var->pipefd[1]);
			if (in_fd != STDIN_FILENO)
				close(in_fd);
			in_fd = var->pipefd[0];
			cmd_start = cmd_end;
			var->args = cmd_end;
		}
	}
	execute_pipe_wait();
}


void	exec_pipes(int pipe_found, t_util *var)
{
	pid_t	pid;
	
	if (pipe_found)
	{
		execute_pipe(var);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			handle_redirections(var);
			ft_execvp(var->args[0], var->args);
			printf("%s: command not found\n", var->args[0]);
			ft_freemap(var->args);
			free(var->input);
			exit(127);
		}
		else if (pid < 0)
			perror("fork");
		else
			exit_child_process(pid);
	}
}
