/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:49:15 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/15 18:39:48 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear2(t_list **lst, void (*del)(void *))
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

t_list	*ft_lstnew2(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back2(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*create_new_node(void *content, t_list **new_lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = ft_lstnew2(content);
	if (!tmp)
	{
		ft_lstclear2(new_lst, del);
		return (NULL);
	}
	ft_lstadd_back2(new_lst, tmp);
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
		if (!create_new_node(content, &new_lst, del))
		{
			ft_lstclear2(&new_lst, del);
			return (NULL);
		}
		prev = prev->next;
	}
	return (new_lst);
}
