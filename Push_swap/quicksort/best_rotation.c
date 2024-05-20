/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:01:52 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/21 00:43:39 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/t_list.h"

void	best_rotation(int is_a, int index, int size, t_list **stack)
{
	if (index > size / 2)
	{
		if (is_a)
			n_reverse_rotate("rra", size - index, stack);
		else
			n_reverse_rotate("rrb", size - index, stack);
	}
	else
	{
		if (is_a)
			n_rotate("ra", index, stack);
		else
			n_rotate("rb", index, stack);
	}
}

void	dual_r(int cheapest_i, int insert_i, t_list **a, t_list **b)
{
	if (cheapest_i > insert_i)
	{
		n_rotate_both(insert_i, a, b);
		n_rotate("ra", cheapest_i - insert_i, a);
	}
	else
	{
		n_rotate_both(cheapest_i, a, b);
		n_rotate("rb", insert_i - cheapest_i, b);
	}
}

void	dual_rr(int cheapest_i, int insert_i, t_list **a, t_list **b)
{
	if (cheapest_i > insert_i)
	{
		n_reverse_rotate_both(insert_i, a, b);
		n_reverse_rotate("rra", cheapest_i - insert_i, a);
	}
	else
	{
		n_reverse_rotate_both(cheapest_i, a, b);
		n_reverse_rotate("rrb", insert_i - cheapest_i, b);
	}
}

void	best_dual_rotation(t_list **a, t_list **b)
{
	int	cheapest_index;
	int	insert_index;
	int	size_a;
	int	size_b;

	cheapest_index = find_cheapest_index(ft_lstsize(*a), ft_lstsize(*b), a, b);
	insert_index = find_insert_index(find_cheapest_value(cheapest_index, a), b);
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	if (cheapest_index > size_a / 2 && insert_index > size_b / 2)
	{
		dual_rr(size_a - cheapest_index, size_b - insert_index, a, b);
	}
	else if (cheapest_index <= size_a / 2 && insert_index <= size_b / 2)
	{
		dual_r(cheapest_index, insert_index, a, b);
	}
	else
	{
		best_rotation(1, cheapest_index, size_a, a);
		best_rotation(0, insert_index, size_b, b);
	}
}
