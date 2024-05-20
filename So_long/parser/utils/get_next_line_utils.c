/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:10:22 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/23 00:41:05 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_next_return_index(char *buffer, int start_index)
{
	int	i;

	i = start_index;
	while (buffer[i])
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*output;
	int		i;
	int		j;

	output = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		output[i + j] = s2[j];
		j++;
	}
	output[i + j] = '\0';
	return (output);
}

char	*extract_line(char *str, int start_index, int *index)
{
	char	*extracted;
	int		i;

	i = start_index;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	extracted = (char *) malloc((i - start_index + 1) * sizeof(char));
	if (extracted == NULL)
		return (NULL);
	i = start_index;
	while (str[i] != '\n' && str[i] != '\0')
	{
		extracted[i - start_index] = str[i];
		(*index)++;
		i++;
	}
	if (str[i] == '\n')
		(*index)++;
	extracted[i - start_index] = '\0';
	return (extracted);
}
