/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:57:39 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/13 15:37:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main/minishell.h"

int	cmd_new_elem(t_cmd **new, int infile, int outfile, char **cmd_param)
{
	(*new) = malloc(sizeof(t_cmd));
	if (*new == NULL)
		return (0);
	(*new)->skip_cmd = 0;
	(*new)->infile = infile;
	(*new)->outfile = outfile;
	(*new)->cmd_param = cmd_param;
	(*new)->next = NULL;
	(*new)->prev = NULL;
	return (1);
}

int	append_cmd(t_cmd **list, int infile, int outfile, char **cmd_param)
{
	t_cmd	*new;

	if (!cmd_new_elem(&new, infile, outfile, cmd_param))
		return (0);
	if (!(*list))
	{
		(*list) = new;
		(*list)->prev = *list;
		(*list)->next = *list;
	}
	else
	{
		new->prev = (*list)->prev;
		new->next = (*list);
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	return (1);
}

void	free_data_cmd(t_cmd *temp)
{
	if (temp->infile > 0)
		close(temp->infile);
	temp->infile = -2;
	if (temp->outfile > 0)
		close(temp->outfile);
	temp->outfile = -2;
	free_array(temp->cmd_param);
}

void	free_cmd(t_cmd **list)
{
	t_cmd	*temp;
	t_cmd	*current;

	if (!(*list))
		return ;
	current = *list;
	while (current->next != *list)
	{
		temp = current;
		current = current->next;
		free_data_cmd(temp);
		free(temp);
	}
	free_data_cmd(current);
	free(current);
	*list = NULL;
}

size_t	len_cmd(t_cmd *list)
{
	t_cmd	*temp;
	size_t	i;

	if ((list))
	{
		temp = list;
		i = 1;
		while (temp->next != list)
		{
			++i;
			temp = temp->next;
		}
		return (i);
	}
	return (0);
}
