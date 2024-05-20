/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:18:27 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/18 22:19:41 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/t_list.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst || !lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
