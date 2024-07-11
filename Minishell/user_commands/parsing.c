/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:53:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 00:26:51 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

// void	quotes_handling(int *in_quotes, char c, char *quote_char)
// {
// 	if (c == '\'' || c == '"')
// 	{
// 		if (*in_quotes && c == *quote_char)
// 		{
// 			*in_quotes = 0;
// 		}
// 		else if (!(*in_quotes))
// 		{
// 			*in_quotes = 1;
// 			*quote_char = c;
// 		}
// 	}
// }

// void	parsing_init(int *size, int *in_quotes, int *start, char *quote_char)
// {
// 	*size = 0;
// 	*in_quotes = 0;
// 	*start = 0;
// 	*quote_char = 0;
// }

// char	**parse_user_input(char *input)
// {
// 	char	**result;
// 	int		size;
// 	int		in_quotes;
// 	int		start;
// 	char	quote_char;

// 	result = malloc(ft_strlen(input) * sizeof(char *));
// 	if (result == NULL)
// 		return (NULL);
// 	parsing_init(&size, &in_quotes, &start, &quote_char);
// 	for (int i = 0; input[i] != '\0'; i++)
// 	{
// 		quotes_handling(&in_quotes, input[i], &quote_char);
// 		if (input[i] == '|' && !in_quotes)
// 		{
// 			if (i > start)
// 			{
// 				size++;
// 				result[size - 1] = ft_strndup(input + start, i - start);
// 			}
// 			size++;
// 			result[size - 1] = ft_strndup("|", 1);
// 			start = i + 1;
// 			continue;
// 		}
// 		if (ft_isspace(input[i]) && !in_quotes)
// 		{
// 			if (i > start)
// 			{
// 				size++;
// 				result[size - 1] = ft_strndup(input + start, i - start);
// 			}
// 			start = i + 1;
// 			while (ft_isspace(input[start]))
// 				start++;
// 			i = start - 1;
// 		}
// 	}
// 	if (ft_strlen(input) > start)
// 	{
// 		size++;
// 		result[size - 1] = ft_strndup(input + start, ft_strlen(input) - start);
// 	}
// 	result[size] = NULL;
// 	for (int i = 0; result[i]; i++)
// 		printf("[%s]\n", result[i]);
// 	return (result);
// }

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
	for (int i = 0; tokens[i]; i++)
		printf("[%s]\n", tokens[i]);
	return (tokens);
}