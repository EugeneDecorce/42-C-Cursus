/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:47:47 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/24 10:59:24 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/t_list.h"

int	ft_lstget_last(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->content);
}
