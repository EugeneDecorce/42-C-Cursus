/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:57:16 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/21 00:33:10 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "headers/push_swap.h"
#include "headers/t_list.h"
#include <time.h>

t_list *generate_list(int n) {
    t_list *head = NULL;
    for (int i = 0; i < n; i++) {
        t_list *new_node = malloc(sizeof(t_list));
        if (new_node == NULL) {
            return NULL;
        }
        new_node->content = rand() - RAND_MAX / 2; 
		//new_node->content = (rand() % (100 - (-100) + 1)) + (-100);
        new_node->next = head;
        head = new_node;
    }

    return head;
}

int is_sorted(t_list *head) {
    if (head == NULL) {
        return 1;
    }

    t_list *current = head;
    while (current->next != NULL) {
        if (current->content > current->next->content) {
            return 0;
        }
        current = current->next;
    }

    return 1;
}

void print_stacks(t_list *a, t_list *b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = a;
	temp_b = b;
	printf("Stack A: ");
	for(int i = 0; temp_a != NULL; i++, temp_a = temp_a->next)
	{
		printf("%d ", temp_a->content);
	}
	printf("\n");
	printf("Stack B: ");
	for(int i = 0; temp_b != NULL; i++, temp_b = temp_b->next)
	{
		printf("%d ", temp_b->content);
	}
	printf("\n");
}

int	is_test_valid(t_list **lst)
{
	t_list *tmp_a;
	int	index_a;
	t_list *tmp_b;
	int	index_b;

	tmp_a = *lst;
	index_a = 0;
	while (tmp_a)
	{
		tmp_b = *lst;
		index_b = 0;
		while (tmp_b)
		{
			if (index_a != index_b && tmp_a->content == tmp_b->content)
				return (0);
			index_b++;
			tmp_b = tmp_b->next;
		}
		index_a++;
		tmp_a = tmp_a->next;
	}
	return (1);
}

int main() {
	srand(time(NULL));
	int i;
	t_list *a;
	t_list *b;

	i = 0;
	while (1)
	{
		a = generate_list(100);
		b = NULL;
		if (!is_test_valid(&a))
		{
			write(1, "Error\n", 6);
			print_stacks(a, b);
			continue;
		}
		instructions_count = 0;
		quicksort(&a, &b);
		if (!is_sorted(a))
		{
			printf("FAILED: ");
			print_stacks(a, b);
		}
		if (instructions_count > 700)
		{
			printf("TOO MUCH INSTRUCTIONS: %d\n", instructions_count);
		}
		//printf("Size %d -> %d\n", i, instructions_count);
		if (i % 1000 == 0)
			printf("%d\n", i);
		i++;
	}
	return 0;
}
*/