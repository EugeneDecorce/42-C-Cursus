/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:53:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/10 18:53:47 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	parse_user_input_logic(int *i, char *input, char ***tokens, int *count)
{
	while (*i < ft_strlen(input) && (ft_isspace((input)[*i])
		|| input[*i] == '\'' || (input)[*i] == '\"'))
		(*i)++;
	(*tokens)[*count] = ft_substr(input, *i,
			next_occ(input, *i + 1, " \'\"\n\t\r\a|", 0));
	if ((*tokens)[*count] == NULL)
		return (1);
	*i += next_occ(input, *i + 1, " \'\"\n\t\r\a|", 0) - *i + 1;
	(*count)++;
	while (*i < ft_strlen(input) && (ft_isspace((input)[*i])
		|| input[*i] == '\'' || input[*i] == '\"'))
		(*i)++;
	while (input[*i] == '|')
	{
		(*tokens)[*count] = ft_substr(input, *i, *i);
		if ((*tokens)[*count] == NULL)
			return (1);
		(*count)++;
		(*i)++;
	}
	return (0);
}

char	**parse_user_input(char *input)
{
	char	**tokens;
	int		count;
	int		i;

	i = 0;
	count = 0;
	tokens = (char **) malloc(MAX_ARGS * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	while (i < ft_strlen(input) && input[i])
	{
		if (count >= MAX_ARGS - 2)
		{
			printf("Too many args\n");
			return (NULL);
		}
		if (parse_user_input_logic(&i, input, &tokens, &count))
			return (NULL);
	}
	tokens[count] = NULL;
	return (tokens);
}
