/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:04:29 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/20 08:01:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	export_validity(char *str);
int export_casual_content(t_list *env);
int search_value(char *str, t_list *env);

void	update_env_variable(t_list **env, int index, char *value)
{
	int	i;

	i = 0;
	while (i < index)
	{
		(*env) = (*env)->next;
		i++;
	}
	free((*env)->str);
	(*env)->str = value;
}

int	export_variable(char *str, t_list **env)
{
	int		value_index;
	char	*value;

	value_index = search_value(str, *env);
	value = ft_strdup(str);
	if (!value)
		return (0);
	if (value_index >= 0)
	{
		update_env_variable(env, value_index, value);
	}
	else if (value_index == -1)
	{
		if (!append(env, value))
			return (0);
	}
	return (1);
}

int	process_export_variables(char **str, t_list **env)
{
	int	exit_code;
	int	i;

	exit_code = 0;
	i = 1;
	while (str[i])
	{
		if (!export_validity(str[i]))
		{
			printf("export_variable: invalid identifier\n");
			exit_code = 1;
		}
		else if (!export_variable(str[i], env))
		{
			printf("malloc error\n");
			return (1);
		}
		i++;
	}
	return (exit_code);
}

int	ft_export(char **str, t_list **env)
{
	if (!str || !str[1])
	{
		if (*env && !export_casual_content(*env))
		{
			printf("malloc error\n");
			return (1);
		}
		return (0);
	}
	return (process_export_variables(str, env));
}

