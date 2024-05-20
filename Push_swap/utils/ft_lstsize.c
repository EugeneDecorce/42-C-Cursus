/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:43:57 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/21 00:37:23 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/t_list.h"

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
