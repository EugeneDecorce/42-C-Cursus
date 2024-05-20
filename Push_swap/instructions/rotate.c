/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:45:03 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/19 17:26:51 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/t_list.h"

void	rotate(char *msg, t_list **stack)
{
	ft_lstadd_back(stack, ft_lstnew((*stack)->content));
	ft_lstdel_first(stack);
	if (ft_strlen(msg) != 0)
		instructions_count++;
	//write(1, msg, ft_strlen(msg));
	//write(1, "\n", 1);
}
//if (ft_strlen(msg) != 0)
//	instructions_count++;

void	n_rotate(char *msg, int n, t_list **stack)
{
	while (n > 0)
	{
		rotate(msg, stack);
		n--;
	}
}

void	rotate_both(t_list **stack1, t_list **stack2)
{
	instructions_count++;
	//write(1, "rr\n", 3);
	rotate("", stack1);
	rotate("", stack2);
}
//instructions_count++;

void	n_rotate_both(int n, t_list **stack1, t_list **stack2)
{
	while (n > 0)
	{
		rotate_both(stack1, stack2);
		n--;
	}
}
