/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:07:12 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/25 09:20:28 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	global_arg_len(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			i++;
		if (str[i - 1] >= '0' && str[i - 1] <= '9')
			count++;
		if (str[i] && !(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			return (0);
	}
	return (count);
}

char	**convert_global_var(char *str)
{
	char	**output;
	int		len;
	int		i;
	int		j;
	int		k;

	len = global_arg_len(str);
	output = allocate_output(len, &i, &k);
	if (output == NULL)
		return (NULL);
	while (i < len)
	{
		while (str[k] == ' ')
			k++;
		j = 0;
		while (str[k] && str[k] != ' ')
			output[i][j++] = str[k++];
		output[i][j] = '\0';
		i++;
	}
	output[i] = NULL;
	return (output);
}

char	**allocate_output(int len, int *i, int *k)
{
	char	**output;

	*i = 0;
	*k = 0;
	output = (char **)malloc((len + 1) * sizeof(char *));
	if (output == NULL)
		return (NULL);
	while (*i < len)
	{
		output[*i] = (char *)malloc(12 * sizeof(char));
		if (output[*i] == NULL)
		{
			free_map(output, *i);
			return (NULL);
		}
		(*i)++;
	}
	return (output);
}
