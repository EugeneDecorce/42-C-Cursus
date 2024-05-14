/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:22:30 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/21 00:45:02 by edecorce         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		len;
	
	argv++;
	len = argc - 1;
	if (!is_stack_valid(len, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	a = convert_to_stack(len, argv);
	b = NULL;
	quicksort(&a, &b);
	return (0);
}
