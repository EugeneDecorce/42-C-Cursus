/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:00:25 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/20 07:30:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main/minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strncmp("echo", cmd, INT_MAX) || !ft_strncmp("cd", cmd, INT_MAX) \
	|| !ft_strncmp("pwd", cmd, INT_MAX) || !ft_strncmp("export", cmd, INT_MAX) \
	|| !ft_strncmp("unset", cmd, INT_MAX) || !ft_strncmp("env", cmd, INT_MAX) \
	|| !ft_strncmp("exit", cmd, INT_MAX))
		return (1);
	return (0);
}

void	exec_builtin(int save_stdout, t_utils *data, t_cmd *cmd)
{
	if (!ft_strncmp("echo", cmd->cmd_param[0], INT_MAX))
		data->exit_code = ft_echo(cmd->cmd_param);
	else if (!ft_strncmp("cd", cmd->cmd_param[0], INT_MAX))
		data->exit_code = ft_cd(data, cmd->cmd_param);
	else if (!ft_strncmp("pwd", cmd->cmd_param[0], INT_MAX))
		data->exit_code = ft_pwd();
	else if (!ft_strncmp("export", cmd->cmd_param[0], INT_MAX))
	{
		printf("[%s]", *cmd->cmd_param);
		data->exit_code = ft_export(cmd->cmd_param, &data->env);
	}
	else if (!ft_strncmp("unset", cmd->cmd_param[0], INT_MAX))
		data->exit_code = ft_unset(cmd->cmd_param, &data->env);
	else if (!ft_strncmp("env", cmd->cmd_param[0], INT_MAX))
		data->exit_code = ft_env(data->env);
	else if (!ft_strncmp("exit", cmd->cmd_param[0], INT_MAX))
	{
		if (cmd->outfile >= 0)
		{
			dup2(save_stdout, 1);
			close(save_stdout);
		}
		ft_exit(data, cmd->cmd_param);
	}
}

int	launch_builtin(t_utils *data, t_cmd *cmd)
{
	int	save_stdout;

	save_stdout = -1;
	if (cmd->outfile >= 0)
	{
		save_stdout = dup(1);
		dup2(cmd->outfile, 1);
	}
	exec_builtin(save_stdout, data, cmd);
	if (cmd->outfile >= 0)
	{
		dup2(save_stdout, 1);
		close (save_stdout);
	}
	return (1);
}

void	built(int *pip, t_cmd *cmd, t_utils *data)
{
	close(pip[0]);
	if (cmd->outfile < 0 && cmd->next != data->cmd)
		cmd->outfile = pip[1];
	else
		close(pip[1]);
	launch_builtin(data, cmd);
}