/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:43:40 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/19 17:27:15 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "t_list.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

#include <stdio.h>

int		instructions_count;

int		ft_strlen(char *str);
void	sort_three(t_list **a);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_swap(int *a, int *b);
int		ft_atoi(const char *str);
int		ft_lstlast(t_list **lst);
void	ft_lstclear(t_list **lst);
int		ft_lstget_last(t_list *a);
void	ft_lstdel_last(t_list **lst);
void	ft_lstdel_first(t_list **lst);
long	ft_atoi_long(const char *str);
int		ft_contains(char *str, char c);
int		is_stack_valid(int *argc, char ***argv, int *is_global_arg);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

void	push(char *msg, t_list **stack1, t_list **stack2);
void	n_push(char *msg, int n, t_list **stack1, t_list **stack2);

void	swap(char *msg, t_list **stack);
void	n_swap(char *msg, int n, t_list **stack);
void	swap_both(t_list **stack1, t_list **stack2);
void	n_swap_both(int n, t_list **stack1, t_list **stack2);

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