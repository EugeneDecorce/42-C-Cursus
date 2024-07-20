/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_administration.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:04:15 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/20 06:26:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main/minishell.h"

int	open_file(t_utils *data, char *filename, int type)
{
	int	fd;

	fd = -2;
	if (type == 1)
		fd = open(filename, O_RDONLY, 0644);
	else if (type == 2)
		fd = here_doc(data, filename);
	else if (type == 3)
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == 4)
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (type != 2 && fd < 0)
		printf("%s", filename);
	return (fd);
}

int	get_in(t_utils *data, t_token *tmp, t_cmd *cmd)
{
	if (tmp->type == 1)
	{
		if (cmd->infile >= 0)
			close(cmd->infile);
		if (tmp == tmp->next || tmp->next->type <= 5)
		{
			print_error_token(tmp, data);
			return (0);
		}
		cmd->infile = open_file(data, tmp->next->str, 1);
		if (cmd->infile == -1)
			return (0);
	}
	else if (tmp->type == 2)
	{
		if (cmd->infile >= 0)
			close(cmd->infile);
		if (tmp == tmp->next || tmp->next->type <= 5)
			return (print_error_token(tmp, data));
		cmd->infile = open_file(data, tmp->next->str, 2);
		if (cmd->infile == -1)
			return (0);
	}
	return (1);
}

int	get_infile(t_utils *data, t_token *token, t_cmd *cmd)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->type != 5 && !get_in(data, tmp, cmd))
		return (0);
	if (tmp->type == 5)
		return (1);
	tmp = tmp->next;
	while (tmp->type != 5 && tmp != data->token)
	{
		if (!get_in(data, tmp, cmd))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_out(t_token *tmp, t_cmd *cmd, t_utils *data)
{
	if (tmp->type == 3)
	{
		if (cmd->outfile >= 0)
			close(cmd->outfile);
		if (tmp == tmp->next || tmp->next->type <= 5)
			return (print_error_token(tmp, data));
		cmd->outfile = open_file(NULL, tmp->next->str, 3);
		if (cmd->outfile == -1)
			return (0);
	}
	else if (tmp->type == 4)
	{
		if (cmd->outfile >= 0)
			close(cmd->outfile);
		if (tmp == tmp->next || tmp->next->type <= 5)
			return (print_error_token(tmp, data));
		cmd->outfile = open_file(NULL, tmp->next->str, 4);
		if (cmd->outfile == -1)
			return (0);
	}
	return (1);
}

int	get_outfile(t_token *token, t_cmd *cmd, t_utils *data)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->type != 5 && !get_out(tmp, cmd, data))
		return (0);
	tmp = tmp->next;
	while (tmp != data->token && tmp->type != 5)
	{
		if (!get_out(tmp, cmd, data))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
