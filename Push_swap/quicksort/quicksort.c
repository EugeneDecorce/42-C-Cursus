/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:22:23 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/24 11:00:22 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/t_list.h"

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first < second && second > third && third > first)
	{
		reverse_rotate("rra", a);
		swap("sa", a);
	}
	if (first > second && second < third && third > first)
		swap("sa", a);
	if (first < second && second > third && third < first)
		reverse_rotate("rra", a);
	if (first > second && second > third && third < first)
	{
		rotate("ra", a);
		swap("sa", a);
	}
	if (first > second && second < third && third < first)
		rotate("ra", a);
}

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
	int		init;
	int		larger;

	tmp_b = *b;
	init = 0;
	larger = 0;
	if ((*a)->next->content > (*b)->content && (*a)->content > (*b)->content)
		larger = 1;
	while (tmp_b)
	{
		while (!larger && ft_lstget_last(*a) > (*b)->content && !is_sorted(*a))
		{
			reverse_rotate("rra", a);
			if (!init)
				break ;
		}
		push("pa", a, b);
		init = 1;
		tmp_b = *b;
	}
	while (ft_lstget_last(*a) < (*a)->content)
		reverse_rotate("rra", a);
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
	while (ft_lstsize(*a) > 2)
	{
		best_dual_rotation(a, b);
		push("pb", b, a);
	}
	if ((*a)->content > (*a)->next->content)
		swap("sa", a);
	arrange_stack_b(b);
	push_back(a, b);
}
