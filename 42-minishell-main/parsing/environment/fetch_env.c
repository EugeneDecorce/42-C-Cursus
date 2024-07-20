/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:52:38 by handler           #+#    #+#             */
/*   Updated: 2024/07/15 03:24:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main/minishell.h"

int	search_env_val(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (0);
}

int	word_limit(char *str, char *env)
{
	int	i;

	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		++i;
	if (i == search_env_val(env, '='))
		return (i);
	return (0);
}

int	exist_in_env(char *line, int *i, t_utils *data)
{
	t_list	*temp;
	int		len;

	if (line[*i + 1] == '?' || line[*i + 1] == '$')
		return (2);
	temp = data->env;
	len = ft_lstsize(temp);
	while (len--)
	{
		if (ft_strncmp(temp->str, &line[*i + 1], \
			word_limit(&line[*i + 1], temp->str)) == 0)
		{
			*i += ft_strlen(temp->str) - \
				ft_strlen(ft_strchr(temp->str, '=')) + 1;
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

char	*get_envelem(t_list *env, char *key)
{
	t_list	*temp;
	int		len;
	int		t;

	if (!key)
		return (NULL);
	temp = env;
	len = ft_lstsize(temp);
	t = ft_strlen(key);
	while (len--)
	{
		if (ft_strncmp(temp->str, key, t) == 0)
		{
			len = 0;
			while (temp->str[len])
				if (temp->str[len++] == '=')
					break ;
			return (ft_strdup(&(temp->str[len])));
		}
		temp = temp->next;
	}
	return (NULL);
}

char	*get_envvar(char *line, int size)
{
	char	*dollar;
	int		i;

	dollar = malloc(sizeof(char) * size);
	if (!dollar)
		return (NULL);
	i = 0;
	while (line[++i] && i < size)
		dollar[i - 1] = line[i];
	dollar[i - 1] = '\0';
	return (dollar);
}
