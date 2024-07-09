/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetchenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:00:14 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/08 19:09:24 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	ft_fetchenv_len(char *str)
{
	char	*substr;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (is_in_quote(str, i) < 2 && str[i] == '$'
			&& (env_delim(str, i + 1) - i) > 0)
		{
			substr = ft_substr(str, i + 1, env_delim_noq(str, i + 1));
			if (substr == NULL)
				return (0);
			len += ft_strlen(getenv(substr));
			i += ft_strlen(substr);
			free(substr);
		}
		else
			len++;
		i++;
	}
	return (len);
}

int	ft_fetchenv_helper(char **output, char *str, int *i, int *j)
{
	char	*substr;
	char	*arg;
	int		k;

	k = 0;
	substr = ft_substr(str, *i + 1, env_delim_noq(str, *i + 1));
	if (substr == NULL)
	{
		printf("O");
		return (0);
	}
	arg = getenv(substr);
	while (arg != NULL && arg[k])
	{
		(*output)[*j] = arg[k];
		(*j)++;
		k++;
	}
	*i += ft_strlen(substr);
	free(substr);
	return (1);
}

char	*ft_fetchenv(char *str)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_fetchenv_len(str) == 0)
		return (NULL);
	output = (char *) malloc((ft_fetchenv_len(str) + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	while (str[i])
	{
		if (is_in_quote(str, i) < 2 && str[i] == '$'
			&& env_delim(str, i + 1) - i > 0)
		{
			if (!ft_fetchenv_helper(&output, str, &i, &j))
				return (free(output), NULL);
		}
		else
			output[j++] = str[i];
		i++;
	}
	output[j] = '\0';
	return (output);
}
