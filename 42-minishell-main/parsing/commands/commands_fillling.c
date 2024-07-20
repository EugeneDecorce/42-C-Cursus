/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_fillling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:40:06 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/15 05:13:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main/minishell.h"

int	fill_cmd(t_utils *data, t_token *temp)
{
	if (!get_infile(data, temp, data->cmd->prev) && \
		data->cmd->prev->infile != -1)
		return (0);
	if (data->cmd->prev->infile == -1)
	{
		data->cmd->prev->skip_cmd = 1;
		data->cmd->prev->outfile = -1;
		return (1);
	}
	if (!get_outfile(temp, data->cmd->prev, data) && data->cmd->prev->outfile \
		!= -1)
		return (0);
	if (data->cmd->prev->outfile == -1)
	{
		if (data->cmd->prev->infile >= 0)
			close (data->cmd->prev->infile);
		data->cmd->prev->skip_cmd = 1;
		data->cmd->prev->infile = -1;
		return (1);
	}
	data->cmd->prev->cmd_param = get_param(data, temp);
	if (!data->cmd->prev->cmd_param)
		free_data(data, "malloc error\n", 1);
	return (1);
}

int	valid(t_utils *data, t_token *temp)
{
	if (!append_cmd(&data->cmd, -2, -2, NULL))
		free_data(data, "malloc error\n", 1);
	if (!fill_cmd(data, temp))
	{
		data->exit_code = 2;
		return (0);
	}
	return (1);
}

int	create_list_cmd(t_utils *data)
{
	t_token	*temp;

	temp = data->token;
	if (!valid(data, temp))
		return (0);
	temp = temp->next;
	while (temp != data->token)
	{
		if (temp->prev->type == 5)
		{
			if (!valid(data, temp))
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}
