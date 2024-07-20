/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:29:58 by handler           #+#    #+#             */
/*   Updated: 2024/07/15 05:19:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main/minishell.h"

int	recreate_path(char *dest, char *str, char *env, int *index)
{
	int	i;
	int	j;

	i = 0;
	while (*index < (PATH_MAX - 1) && env[(*index)] && env[(*index)] != ':')
		dest[i++] = env[(*index)++];
	++(*index);
	dest[i++] = '/';
	j = 0;
	while (j < (PATH_MAX - 1) && str[j])
		dest[i++] = str[j++];
	dest[i] = '\0';
	return (0);
}

char	*create_paths(t_list *env, int len)
{
	t_list	*temp;

	temp = env;
	while (len--)
	{
		if (ft_strncmp(temp->str, "PATH=", 5) == 0)
			return (&(temp->str[5]));
		temp = temp->next;
	}
	return (NULL);
}
