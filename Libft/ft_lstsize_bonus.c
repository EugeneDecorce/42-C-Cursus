/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:08:25 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/10 19:19:05 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*prev;

	prev = lst;
	len = 0;
	while (prev)
	{
		prev = prev->next;
		len++;
	}
	return (len);
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
	printf("%d", ft_lstsize(lst));
	return 0;
}*/