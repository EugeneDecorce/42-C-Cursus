/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:53:44 by handler           #+#    #+#             */
/*   Updated: 2024/07/15 04:37:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main/minishell.h"

int	env_exitstatus(t_utils *data, char **str)
{
	char	*temp;
	char	*tmp2;

	temp = ft_itoa(data->exit_code);
	if (!temp)
		return (0);
	tmp2 = ft_strjoin(*str, temp);
	free(temp);
	free(*str);
	if (!tmp2)
		return (0);
	*str = tmp2;
	return (1);
}

int	in_env(t_utils *data, char *line, int size, char **str)
{
	char	*temp;
	char	*key;
	char	*value;

	key = get_envvar(line, size);
	value = get_envelem(data->env, key);
	if (key)
		free(key);
	temp = ft_strjoin(*str, value);
	if (value)
		free(value);
	free(*str);
	if (!temp)
		return (0);
	*str = temp;
	return (1);
}

int	add_to_env(char *line, int *index, char **str, t_utils *data)
{
	int		ctrl;
	int		n;

	n = *index;
	ctrl = exist_in_env(line, index, data);
	if (ctrl == 1)
		return (in_env(data, &line[n], *index - n, str));
	else if (ctrl == 2)
	{
		(*index) += 2;
		return (env_exitstatus(data, str));
	}
	else
	{
		++(*index);
		while (line[*index] && \
			(ft_isalnum(line[*index]) || line[*index] == '_'))
			++(*index);
		return (1);
	}
}

int	add_char(char *c, char **str, t_utils *data, int *index)
{
	char	char_to_str[2];
	char	*tmp2;
	int		i;

	i = 0;
	if (c[i] == '$' && !data->sq && exist_in_env(c, &i, data))
		return (1);
	char_to_str[0] = *c;
	char_to_str[1] = '\0';
	(*index)++;
	tmp2 = ft_strjoin(*str, char_to_str);
	free(*str);
	if (!tmp2)
		return (0);
	*str = tmp2;
	return (1);
}

int	replace_env(char **line, t_utils *data)
{
	int	dq;
	int		i;
	char	*str;

	i = 0;
	dq = 0;
	data->sq = 0;
	str = ft_strdup("");
	while ((*line)[i])
	{
		quote_selection(&dq, &data->sq, NULL, (*line)[i]);
		if ((*line)[i] && (*line)[i + 1] && (*line)[i] == '$' && \
			((*line)[i + 1] != '\'' && (*line)[i + 1] != '"') && \
			(ft_isalpha((*line)[i + 1]) || (*line)[i + 1] == '?' || \
			(*line)[i + 1] == '_') && !data->sq && \
			!add_to_env((*line), &i, &str, data))
			return (0);
		if ((*line)[i] && !add_char(&(*line)[i], &str, data, &i))
			return (0);
	}
	free(*line);
	*line = str;
	return (1);
}
