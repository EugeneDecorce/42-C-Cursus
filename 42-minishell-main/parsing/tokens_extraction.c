/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_extraction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:02:52 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/15 04:52:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	add_command(t_token **begin, char **command);

int	update_commands(t_token **begin, char **command)
{
	int	spe;

	spe = tokenned_input(*command);
	if (!spe)
		return (0);
	if (spe == 1 && !append_token(begin, ft_strdup("<"), 1))
		return (0);
	else if (spe == 2 && !append_token(begin, ft_strdup("<<"), 2))
		return (0);
	else if (spe == 3 && !append_token(begin, ft_strdup(">"), 3))
		return (0);
	else if (spe == 4 && !append_token(begin, ft_strdup(">>"), 4))
		return (0);
	else if (spe == 5 && !append_token(begin, ft_strdup("|"), 5))
		return (0);
	if (spe == 1 || spe == 3 || spe == 5)
		(*command)++;
	else if (spe == 2 || spe == 4)
		(*command) += 2;
	return (1);
}

int	create_list_token(t_token **begin, char *command)
{
	(*begin) = NULL;
	while (*command)
	{
		while (ft_isspace(*command))
			command++;
		if (*command && !tokenned_input(command) && !add_command(begin, &command))
		{
			if (*begin)
				free_token(begin);
			return (0);
		}
		else if (*command && tokenned_input(command) && \
					!update_commands(begin, &command))
		{
			if (*begin)
				free_token(begin);
			return (0);
		}
	}
	return (1);
}

int	command_length(char *command, int *quotes)
{
	int	len;

	len = 0;
	*quotes = 0;
	while (command[len] && !ft_isspace(command[len]) && !tokenned_input(command + len))
	{
		if (command[len] == '"' || command[len] == '\'')
		{
			(*quotes)++;
			if (command[len++] == '"')
				while (command[len] && command[len] != '"')
					++len;
			else
				while (command[len] && command[len] != '\'')
					++len;
			if (command[len])
				++len;
		}
		if (command[len] && command[len] != '"' && command[len] != '\'' && \
			!ft_isspace(command[len]) && !tokenned_input(command + len))
			++len;
	}
	return (len);
}

void	token_duped(char *command, int length, char *str, int i)
{
	int	j;

	j = 0;
	while (command[i + j] && i < length)
	{
		if (command[i + j] == '\'' && ++j)
		{
			while (command[i + j] != '\'' && ++i)
				str[i - 1] = command[(i - 1) + j];
			j++;
		}
		else if (command[i + j] == '"' && ++j)
		{
			while (command[i + j] != '"' && ++i)
				str[i - 1] = command[(i - 1) + j];
			j++;
		}
		else
		{
			str[i] = command[i + j];
			i++;
		}
	}
	str[i] = 0;
}

int	add_command(t_token **begin, char **command)
{
	char	*str;
	int		length;
	int		quotes;
	int		i;

	i = 0;
	length = command_length(*command, &quotes);
	if (((length) - (2 * quotes)) < 0)
		return (1);
	str = malloc(sizeof(char) * ((length + 1) - (2 * quotes)));
	if (!str)
		return (0);
	token_duped(*command, length - (2 * quotes), str, i);
	if (!append_token(begin, str, 0))
		return (0);
	if ((*begin)->prev == (*begin) || (*begin)->prev->prev->type == 5)
		(*begin)->prev->type = 6;
	else
		(*begin)->prev->type = 7;
	(*command) += length;
	return (1);
}


