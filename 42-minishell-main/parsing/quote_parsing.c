/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:58:47 by handler           #+#    #+#             */
/*   Updated: 2024/07/20 06:09:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	start_quote(int *dq, int *sq, int *index, char c)
{
	if (c == '\'' && !*dq)
		*sq = 1;
	else if (c == '"' && !*sq)
		*dq = 1;
	if (index)
		++(*index);
}

void	end_quote(int *dq, int *sq, int *index, char c)
{
	if (c == '\'' && !*dq && *sq)
		*sq = 0;
	else if (c == '"' && !*sq && *dq)
		*dq = 0;
	if (index)
		++(*index);
}

void	quote_selection(int *dq, int *sq, int *index, char c)
{
	if ((c == '\'' || c == '"') && !*sq && !*dq)
		start_quote(dq, sq, index, c);
	else if ((c == '\'' || c == '"'))
		end_quote(dq, sq, index, c);
}

int	open_quote(t_utils *data, char *line)
{
	int	dq;
	int	sq;
	int		i;

	i = 0;
	dq = 0;
	sq = 0;
	while (line && line[i])
	{
		quote_selection(&dq, &sq, &i, line[i]);
		if (line[i] && line[i] != '\'' && line[i] != '"')
			++i;
	}
	if (dq || sq)
	{
		printf("open quote\n");
		data->exit_code = 2;
		return (1);
	}
	return (0);
}
