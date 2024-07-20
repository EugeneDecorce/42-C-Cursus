/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:02:35 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/15 05:17:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main/minishell.h"

void	child_process(t_utils *data, t_cmd *cmd, int *pip)
{
	char	*path;
	char	**env;

	path = NULL;
	if (cmd->skip_cmd)
		data->exit_code = 1;
	else if (is_builtin(cmd->cmd_param[0]))
		built(pip, cmd, data);
	else if (check_command_viability(&path, data, cmd->cmd_param[0]))
	{
		redirect_in_out(data, cmd, pip);
		env = lst_to_arr(data->env);
		if (!env)
			free_data(data, "malloc error\n", 1);
		rl_clear_history();
		partial_signals();
		execve(path, cmd->cmd_param, env);
		free(env);
	}
	if (path)
		free(path);
	free_data(data, NULL, data->exit_code);
}

void	parent_process(t_utils *data, t_cmd *cmd, int *pip)
{
	close(pip[1]);
	if (cmd->infile >= 0)
		close(cmd->infile);
	if (cmd->infile == -2)
		cmd->infile = pip[0];
	if (cmd->next != data->cmd && cmd->next->infile == -2)
		cmd->next->infile = pip[0];
	else
		close(pip[0]);
}

int	exec_cmd(t_utils *data, t_cmd *cmd, int *pip)
{
	g_signal_pid = fork();
	if (g_signal_pid < 0)
		free_data(data, "fork error\n", 1);
	else if (!g_signal_pid)
	{
		if (cmd->cmd_param && cmd->cmd_param[0])
			child_process(data, cmd, pip);
		else
			free_data(data, NULL, 0);
	}
	else
		parent_process(data, cmd, pip);
	return (1);
}

void	wait_all_pids(t_utils *data)
{
	int		status;
	int		pid;
	int		len;
	t_cmd	*temp;

	temp = data->cmd;
	len = len_cmd(temp);
	while (len--)
	{
		pid = waitpid(0, &status, 0);
		if (pid == g_signal_pid)
		{
			if (WIFEXITED(status))
				data->exit_code = WEXITSTATUS(status);
		}
		if (temp->outfile >= 0)
			close(temp->outfile);
		if (temp->infile >= 0)
			close(temp->infile);
		temp = temp->next;
	}
}

int	exec(t_utils *data)
{
	t_cmd	*temp;
	int		*pip;

	pip = data->pip;
	temp = data->cmd;
	if (temp && temp->skip_cmd == 0 && temp->next == temp && temp->cmd_param[0] \
		&& is_builtin(temp->cmd_param[0]))
		return (launch_builtin(data, temp));
	if (pipe(pip) == -1)
		return (0);
	exec_cmd(data, temp, pip);
	temp = temp->next;
	while (temp != data->cmd)
	{
		if (pipe(pip) == -1)
			return (-1);
		exec_cmd(data, temp, pip);
		temp = temp->next;
	}
	wait_all_pids(data);
	return (1);
}
