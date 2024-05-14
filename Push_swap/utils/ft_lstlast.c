/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:57:52 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/21 00:36:45 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/t_list.h"

int	ft_lstlast(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return (0);
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->content);
}
