/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_modelling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:38:19 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/29 00:33:13 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_fork	*init_fork(int id)
{
	t_fork	*fork;

	fork = (t_fork *) malloc(sizeof(t_fork));
	if (fork == NULL)
		return (NULL);
	fork->id = id;
	fork->taken = 0;
	return (fork);
}

void	add_fork(t_fork *fork)
{
	t_fork	*new_fork;
	t_fork	*tmp;

	if (!fork)
		return ;
	tmp = fork;
	while (tmp->next)
		tmp = tmp->next;
	new_fork = init_fork(tmp->id + 1);
	tmp->next = new_fork;
}

void	close_fork(t_fork *forks)
{
	t_fork	*head;
	t_fork	*tmp;

	if (!forks)
		return ;
	head = forks;
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
}

t_fork	*make_forks(int num)
{
	t_fork	*forks;

	forks = init_fork(0);
	while (num > 1)
	{
		add_fork(forks);
		num--;
	}
	close_fork(forks);
	return (forks);
}
