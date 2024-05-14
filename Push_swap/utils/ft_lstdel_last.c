/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:07:19 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/21 01:17:17 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/t_list.h"

void	ft_lstdel_last(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	free(tmp->next);
	tmp->next = NULL;
}
