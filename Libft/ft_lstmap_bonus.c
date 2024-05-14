/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:49:15 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/11 00:28:10 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!*lst || !lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*create_new_node(void *content, t_list **new_lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = ft_lstnew(content);
	if (!tmp)
	{
		ft_lstclear(new_lst, del);
		return (NULL);
	}
	ft_lstadd_back(new_lst, tmp);
	return (tmp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*prev;
	t_list	*new_lst;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	prev = lst;
	new_lst = NULL;
	while (prev)
	{
		content = f(prev->content);
		if (!content || !create_new_node(content, &new_lst, del))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		prev = prev->next;
	}
	return (new_lst);
}
