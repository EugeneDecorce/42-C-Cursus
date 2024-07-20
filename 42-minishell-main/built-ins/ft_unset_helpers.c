/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:27:17 by user              #+#    #+#             */
/*   Updated: 2024/07/15 01:27:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	is_valid_identifier(char *str)
{
	int	i;

	if (str[0] != '_' && !ft_isalpha(str[0]))
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	does_variable_exist(char *str, t_list *env)
{
	int		i;
	int		j;
	t_list	*temp;

	if (!env)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	j = 0;
	temp = env;
	if (!ft_strncmp(temp->str, str, i))
		return (j);
	temp = temp->next;
	j++;
	while (temp != env)
	{
		if (!ft_strncmp(temp->str, str, i))
			return (j);
		temp = temp->next;
		j++;
	}
	return (-1);
}
