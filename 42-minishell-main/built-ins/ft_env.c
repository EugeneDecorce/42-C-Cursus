/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:47:27 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/13 15:46:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	ft_env(t_list *env)
{
	t_list	*temp;

	temp = env;
	if (temp == NULL)
		return (0);
	if (ft_strchr(temp->str, '='))
		printf("%s\n", temp->str);
	temp = temp->next;
	while (temp != env)
	{
		if (ft_strchr(temp->str, '='))
			printf("%s\n", temp->str);
		temp = temp->next;
	}
	return (0);
}
