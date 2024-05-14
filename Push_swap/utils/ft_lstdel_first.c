/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:11:26 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/21 01:31:33 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/t_list.h"

void	ft_lstdel_first(t_list **lst)
{
	//t_list	*tmp;

	if (!lst || !*lst)
		return ;
	//tmp = *lst;
	*lst = (*lst)->next;
	//free(tmp);
}
