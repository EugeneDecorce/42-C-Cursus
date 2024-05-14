/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:22:23 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/21 01:30:51 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/t_list.h"

void	arrange_stack_b(t_list **b)
{
	t_list	*tmp;
	int		index;

	tmp = *b;
	index = 0;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
		{
			best_rotation(0, index + 1, ft_lstsize(*b), b);
			return ;
		}
		index++;
		tmp = tmp->next;
	}
}

void	push_back(t_list **a, t_list **b)
{
	t_list	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		push("pa", a, b);
		tmp_b = tmp_b->next;
	}
}

int	find_cheapest_value(int cheapest_index, t_list **a)
{
	t_list	*tmp;
	int		index;

	tmp = *a;
	index = 0;
	while (tmp)
	{
		if (index == cheapest_index)
			return (tmp->content);
		index++;
		tmp = tmp->next;
	}
	return ((*a)->content);
}

void	quicksort(t_list **a, t_list **b)
{
	n_push("pb", 2, b, a);
	while (ft_lstsize(*a) > 0)
	{
		best_dual_rotation(a, b);
		push("pb", b, a);
	}
	arrange_stack_b(b);
	push_back(a, b);
}
