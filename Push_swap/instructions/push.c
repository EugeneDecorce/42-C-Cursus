/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:44:00 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/25 08:41:00 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/t_list.h"

void	push(char *msg, t_list **stack1, t_list **stack2)
{
	t_list	*pre;

	if (!stack2 || !(*stack2) || !stack2)
		return ;
	pre = ft_lstnew((*stack2)->content);
	pre->next = *stack1;
	*stack1 = pre;
	ft_lstdel_first(stack2);
	write(1, msg, ft_strlen(msg));
	if (ft_strlen(msg) != 0)
		write(1, "\n", 1);
}
//instructions_count++;

void	n_push(char *msg, int n, t_list **stack1, t_list **stack2)
{
	while (n > 0)
	{
		push(msg, stack1, stack2);
		n--;
	}
}
