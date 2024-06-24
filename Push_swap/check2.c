/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:22:28 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/24 13:56:57 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	convert_global_var2(int len, char ***output, int *i, int *k)
{
	*output = (char **) malloc((len + 1) * sizeof(char *));
	if (*output == NULL)
		return (0);
	*i = 0;
	*k = 0;
	return (1);
}

void	convert_global_var3(char *str, int *k, int*j)
{
	while (str[*k] == ' ')
		(*k)++;
	*j = 0;
}

void	convert_global_var4(int *k, int*j)
{
	(*j)++;
	(*k)++;
}

char	**convert_global_var(char *str)
{
	char	**output;
	int		len;
	int		i;
	int		j;
	int		k;

	len = global_arg_len(str);
	if (!convert_global_var2(len, &output, &i, &k))
		return (NULL);
	while (i < len)
	{
		output[i] = (char *) malloc(12 * sizeof(char));
		if (output[i] == NULL)
			return (free_map(output, i), NULL);
		convert_global_var3(str, &k, &j);
		while (str[k] && str[k] != ' ')
		{
			output[i][j] = str[k];
			convert_global_var4(&k, &j);
		}
		output[i][j] = '\0';
		i++;
	}
	output[i] = NULL;
	return (output);
}

int	is_stack_valid2(int *j, int i, char **argv)
{
	while (*j < i)
	{
		if (*j != i && ft_strcmp(argv[i], argv[*j]) == 0)
			return (0);
		(*j)++;
	}
	return (1);
}
