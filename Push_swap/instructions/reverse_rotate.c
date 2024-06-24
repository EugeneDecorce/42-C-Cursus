/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:48:39 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/24 15:07:11 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/t_list.h"

void	reverse_rotate(char *msg, t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	ft_lstadd_front(stack, ft_lstnew(tmp->content));
	ft_lstdel_last(stack);
	write(1, msg, ft_strlen(msg));
	if (ft_strlen(msg) != 0)
		write(1, "\n", 1);
}

void	n_reverse_rotate(char *msg, int n, t_list **stack)
{
	while (n > 0)
	{
		reverse_rotate(msg, stack);
		n--;
	}
}

void	reverse_rotate_both(t_list **stack1, t_list **stack2)
{
	reverse_rotate("", stack1);
	reverse_rotate("", stack2);
	write(1, "rrr\n", 4);
}

void	n_reverse_rotate_both(int n, t_list **stack1, t_list **stack2)
{
	while (n > 0)
	{
		reverse_rotate_both(stack1, stack2);
		n--;
	}
}
