/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:42:59 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/25 08:41:50 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/t_list.h"

void	swap(char *msg, t_list **stack)
{
	int	content;

	content = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = content;
	write(1, msg, ft_strlen(msg));
	if (ft_strlen(msg) != 0)
		write(1, "\n", 1);
}
//instructions_count++;

void	n_swap(char *msg, int n, t_list **stack)
{
	while (n > 0)
	{
		swap(msg, stack);
		n--;
	}
}

void	swap_both(t_list **stack1, t_list **stack2)
{
	write(1, "ss\n", 3);
	swap("", stack1);
	swap("", stack2);
}

void	n_swap_both(int n, t_list **stack1, t_list **stack2)
{
	while (n > 0)
	{
		swap_both(stack1, stack2);
		n--;
	}
}
