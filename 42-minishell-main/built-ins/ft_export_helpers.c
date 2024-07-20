/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:07:17 by user              #+#    #+#             */
/*   Updated: 2024/07/15 01:15:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	print_variable_declaration(char *variable)
{
	int	i;
	
	i = 0;
	printf("declare -x ");
	while (variable[i] && variable[i] != '=')
	{
		printf("%c", variable[i]);
		i++;
	}
	if (variable[i] == '=')
	{
		printf("=\"%s\"\n", &variable[i + 1]);
	}
	else
	{
		printf("\n");
	}
}

int	export_casual_content(t_list *env)
{
	char	**arr;
	int		i;

	arr = lst_to_arr(env);
	if (!arr)
		return (0);
	sort_array(arr, ft_lstsize(env));
	i = 0;
	while (arr[i])
	{
		print_variable_declaration(arr[i]);
		i++;
	}
	free(arr);
	return (1);
}

int	export_validity(char *str)
{
	int	i;

	i = 0;
	if (!str[0] || (str[0] != '_' && !ft_isalpha(str[0])))
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	compare_env_var(char *str, t_list *env_var)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (!ft_strncmp(env_var->str, str, i) && (env_var->str[i] == '\0' || env_var->str[i] == '='));
}

int	search_value(char *str, t_list *env)
{
	t_list *temp = env;
	int	index = 0;

	temp = env;
	index = 0;
	if (!env)
		return (-1);
	if (compare_env_var(str, temp))
		return (index);
	temp = temp->next;
	index++;
	while (temp != env)
	{
		if (compare_env_var(str, temp))
			return (index);
		temp = temp->next;
		index++;
	}
	return (-1);
}