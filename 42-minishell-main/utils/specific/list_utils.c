/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:43:41 by handler           #+#    #+#             */
/*   Updated: 2024/07/13 15:37:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main/minishell.h"

int	free_list(t_list **list)
{
	t_list	*temp;
	t_list	*current;

	if (!(*list))
		return (0);
	current = *list;
	while (current->next != *list)
	{
		temp = current;
		current = current->next;
		free(temp->str);
		free(temp);
	}
	free(current->str);
	free(current);
	*list = NULL;
	return (0);
}

int	ft_lstnew(t_list **new, char *elem)
{
	(*new) = malloc(sizeof(t_list));
	if (*new == NULL)
		return (0);
	(*new)->str = elem;
	(*new)->next = NULL;
	(*new)->prev = NULL;
	return (1);
}

void	ft_lstaddfront(t_list **list, t_list *new)
{
	(*list) = new;
	(*list)->prev = *list;
	(*list)->next = *list;
}

int	append(t_list **list, char *elem)
{
	t_list	*new;

	if (!ft_lstnew(&new, elem))
		return (0);
	if (!(*list))
		ft_lstaddfront(list, new);
	else
	{
		new->prev = (*list)->prev;
		new->next = (*list);
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	return (1);
}
