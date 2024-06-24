/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:22:30 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/24 15:08:07 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"
#include "headers/t_list.h"

t_list	*convert_to_stack(int len, char **argv)
{
	t_list	*last;
	t_list	*new;
	int		i;

	i = len - 1;
	last = NULL;
	while (i >= 0)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		new->next = last;
		last = new;
		i--;
	}
	return (new);
}

// void print_stacks(t_list *a, t_list *b)
// {
// 	t_list	*temp_a;
// 	t_list	*temp_b;

// 	temp_a = a;
// 	temp_b = b;
// 	printf("Stack A: ");
// 	for(int i = 0; temp_a != NULL; i++, temp_a = temp_a->next)
// 	{
// 		printf("%d ", temp_a->content);
// 	}
// 	printf("\n");
// 	printf("Stack B: ");
// 	for(int i = 0; temp_b != NULL; i++, temp_b = temp_b->next)
// 	{
// 		printf("%d ", temp_b->content);
// 	}
// 	printf("\n");
// }

int	already_sorted(t_list *lst)
{
	t_list	*tmp;
	int		content;

	tmp = lst;
	content = tmp->content;
	while (tmp->next)
	{
		if (tmp->next->content < content)
			return (0);
		tmp = tmp->next;
		content = tmp->content;
	}
	return (1);
}

int	rapid_sort(t_list **a)
{
	if (ft_lstsize(*a) == 2 && (*a)->content > (*a)->next->content)
	{
		swap("sa", a);
		return (1);
	}
	else if (ft_lstsize(*a) == 3)
	{
		sort_three(a);
		return (1);
	}
	return (0);
}

void	free_global_arg(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		len;
	int		is_global_arg;

	if (argc == 1)
		return (1);
	argv++;
	is_global_arg = 0;
	len = argc - 1;
	if (!is_stack_valid(&len, &argv, &is_global_arg))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	a = convert_to_stack(len, argv);
	b = NULL;
	if (already_sorted(a) || rapid_sort(&a))
		return (0);
	quicksort(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	if (is_global_arg == 1)
		free_global_arg(argv);
	return (0);
}
