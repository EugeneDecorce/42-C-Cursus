/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:43:40 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/21 17:19:14 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "t_list.h"
//# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//int		instructions_count;

int		ft_strlen(char *str);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_swap(int *a, int *b);
int		ft_atoi(const char *str);
int		ft_lstlast(t_list **lst);
void	ft_lstdel_last(t_list **lst);
void	ft_lstdel_first(t_list **lst);
int		is_stack_valid(int argc, char **argv);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

void	push(char *msg, t_list **stack1, t_list **stack2);
void	n_push(char *msg, int n, t_list **stack1, t_list **stack2);

void	swap(char *msg, t_list *stack);
void	n_swap(char *msg, int n, t_list *stack);
void	swap_both(t_list *stack1, t_list *stack2);
void	n_swap_both(int n, t_list *stack1, t_list *stack2);

void	rotate(char *msg, t_list **stack);
void	n_rotate(char *msg, int n, t_list **stack);
void	rotate_both(t_list **stack1, t_list **stack2);
void	n_rotate_both(int n, t_list **stack1, t_list **stack2);

void	reverse_rotate(char *msg, t_list **stack);
void	n_reverse_rotate(char *msg, int n, t_list **stack);
void	reverse_rotate_both(t_list **stack1, t_list **stack2);
void	n_reverse_rotate_both(int n, t_list **stack1, t_list **stack2);

void	best_dual_rotation(t_list **a, t_list **b);
void	best_rotation(int is_a, int index, int size, t_list **stack);

void	quicksort(t_list **a, t_list **b);
int		find_insert_index(int content, t_list **b);
int		find_cheapest_value(int cheapest_index, t_list **a);
int		find_cheapest_index(int size_a, int size_b, t_list **a, t_list **b);

#endif /* PUSH_SWAP_H */