/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_with_pipes_helper2.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:29:08 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/09 13:36:32 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	pipes_flow_helper1(int i, int **in_fd,
	int num_commands, int pipe_fds[2])
{
	if (**in_fd != STDIN_FILENO)
		dup2(**in_fd, STDIN_FILENO);
	if (**in_fd != STDIN_FILENO)
		close(**in_fd);
	if (i < num_commands - 1)
	{
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipe_fds[1]);
	}
}

void	pipes_flow_helper2(int num_out_fds, int out_fds[MAX_ARGS])
{
	int	i;

	i = 0;
	while (i < num_out_fds)
	{
		dup2(out_fds[i], STDOUT_FILENO);
		i++;
	}
}

void	pipes_flow_helper3(int num_out_fds, int out_fds[MAX_ARGS])
{
	int	i;

	i = 0;
	while (i < num_out_fds)
	{
		close(out_fds[i]);
		i++;
	}
}

void	pipes_flow_helper0(int out_fds[MAX_ARGS])
{
	int	i;

	i = 0;
	while (i < MAX_ARGS)
	{
		out_fds[i] = 0;
		i++;
	}
}
