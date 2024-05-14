/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_indexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:12:00 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/21 00:48:55 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/t_list.h"

t_list	*find_greatest(t_list **lst)
{
	t_list	*tmp;
	t_list	*greatest;

	tmp = *lst;
	greatest = *lst;
	while (tmp)
	{
		if (tmp->content > greatest->content)
			greatest = tmp;
		tmp = tmp->next;
	}
	return (greatest);
}

int	find_insert_index(int content, t_list **b)
{
	int		greatest_value;
	int		index;
	t_list	*tmp;

	greatest_value = find_greatest(b)->content;
	tmp = *b;
	index = 0;
	while (tmp->next)
	{
		if (tmp->next->content == greatest_value)
		{
			if ((content > tmp->content && content > tmp->next->content)
				|| (content < tmp->content && content < tmp->next->content))
				return (index + 1);
		}
		if (content < tmp->content && content > tmp->next->content)
			return (index + 1);
		index++;
		tmp = tmp->next;
	}
	return (0);
}

int	calculate_count(int index_a, int size_a, int index_b, int size_b)
{
	int	count;

	if (index_a > size_a / 2)
		count = size_a - index_a;
	else
		count = index_a;
	if (index_b > size_b / 2)
		count += size_b - index_b;
	else
		count += index_b;
	return (count);
}

int	find_cheapest_index(int size_a, int size_b, t_list **a, t_list **b)
{
	t_list	*tmp_a;
	int		index_a;
	int		index_b;
	int		cheapest_index;
	int		cheapest_count;

	index_a = 0;
	tmp_a = *a;
	while (tmp_a)
	{
		index_b = find_insert_index(tmp_a->content, b);
		if (calculate_count(index_a, size_a, index_b, size_b)
			< cheapest_count || index_a == 0)
		{
			cheapest_count = calculate_count(index_a, size_a, index_b, size_b);
			cheapest_index = index_a;
		}
		index_a++;
		tmp_a = tmp_a->next;
	}
	return (cheapest_index);
}
