/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:53:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 17:31:53 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	quotes_handling(t_util *var, char c)
{
	if (c == '\'' || c == '"')
	{
		if (var->in_quotes && c == var->quote_char)
		{
			var->in_quotes = 0;
		}
		else if (!(var->in_quotes))
		{
			var->in_quotes = 1;
			var->quote_char = c;
		}
	}
}
int operator_handling(t_util *var, char *input, int i, char *op)
{
    int op_len = strlen(op);
    if (strncmp(input + i, op, op_len) == 0 && !var->in_quotes)
    {
        if (i > var->start)
        {
            var->size += 1;
            var->result[var->size - 1] = ft_strndup(input + var->start, i - var->start);
        }
        var->size += 1;
        var->result[var->size - 1] = ft_strndup(op, op_len);
        var->start = i + op_len;
        return op_len;
    }
    return 0;
}

int pipes_and_redirects_handling(t_util *var, char *input, int i)
{
    if (operator_handling(var, input, i, ">>") > 0) return 2;
    if (operator_handling(var, input, i, "<<") > 0) return 2;
    if (operator_handling(var, input, i, ">") > 0) return 1;
    if (operator_handling(var, input, i, "<") > 0) return 1;
    if (operator_handling(var, input, i, "|") > 0) return 1;
    return 0;
}

void	is_space_handling(t_util *var, char *input, int *i)
{
	if (isspace(input[*i]) && !var->in_quotes)
	{
		if (*i > var->start)
		{
			var->size += 1;
			var->result[var->size - 1]
				= ft_strndup(input + var->start, *i - var->start);
		}
		var->start = *i + 1;
		while (ft_isspace(input[var->start]))
			var->start += 1;
		*i = var->start - 1;
	}
}

void	*parsing_init(t_util *var)
{
	var->result = (char **)malloc(ft_strlen(var->input) * sizeof(char *));
	if (var->result == NULL)
		return (NULL);
	var->size = 0;
	var->in_quotes = 0;
	var->start = 0;
	var->quote_char = 0;
	return (0);
}

char	**parse_user_input(t_util *var)
{
	int		i;

	parsing_init(var);
	i = 0;
	while (var->input[i] != '\0')
	{
		quotes_handling(var, var->input[i]);
		int len;
        if ((len = pipes_and_redirects_handling(var, var->input, i)) > 0)
        {
            i += len;
            continue;
        }
		is_space_handling(var, var->input, &i);
		i++;
	}
	if (ft_strlen(var->input) > var->start)
	{
		var->size += 1;
		var->result[var->size - 1] = ft_strndup(var->input
				+ var->start, ft_strlen(var->input) - var->start);
	}
	var->result[var->size] = NULL;
	for (int i = 0; var->result[i]; i++)
		printf("[%s]\n", var->result[i]);
	return (var->result);
}

