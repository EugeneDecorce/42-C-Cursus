/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:19:23 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/15 18:39:48 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*prev;

	if (!lst)
		return (NULL);
	prev = lst;
	while (prev->next)
		prev = prev->next;
	return (prev);
}
/*
#include <stdio.h>

int main()
{
	t_list *lst;
	t_list *new;
	t_list *new2;

	lst->content = "Hello";
	new->content = "World";
	new2->content = "!";
	lst->next = new;
	new->next = new2;
	new2->next = NULL;
	printf("%s", (char *) ft_lstlast(lst)->content);
	return 0;
}*/