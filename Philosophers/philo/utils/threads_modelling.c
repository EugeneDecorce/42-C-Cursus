/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_modelling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:56:40 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/25 20:00:19 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_list	*init_list(int id)
{
	t_list	*philosopher;

	philosopher = (t_list *) malloc(sizeof(t_list));
	if (philosopher == NULL)
		return (NULL);
	philosopher->id = id;
	if (id % 2 == 1)
		philosopher->delay = 5;
	else
		philosopher->delay = 0;
	philosopher->total_forks = 0;
	philosopher->last_meal_time = get_current_time_ms();
	philosopher->state = 2;
	philosopher->eating_since = 0;
	philosopher->sleeping_since = 0;
	philosopher->total_meals = 0;
	philosopher->next = NULL;
	return (philosopher);
}

void	add_list(t_list *thread)
{
	t_list	*new_thread;
	t_list	*tmp;

	if (!thread)
		return ;
	tmp = thread;
	while (tmp->next)
		tmp = tmp->next;
	new_thread = init_list(tmp->id + 1);
	tmp->next = new_thread;
}

void	close_list(t_list *threads)
{
	t_list	*head;
	t_list	*tmp;

	if (!threads)
		return ;
	head = threads;
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
}

t_list	*make_threads(int num)
{
	t_list	*threads;

	threads = init_list(0);
	while (num > 1)
	{
		add_list(threads);
		num--;
	}
	close_list(threads);
	return (threads);
}

t_create_thread_params	*generate_create_thread_params(t_fork *forks,
	t_times times, t_list *thread, int *still)
{
	t_create_thread_params	*params;

	params = (t_create_thread_params *) malloc(sizeof(t_create_thread_params));
	if (params == NULL)
		return (NULL);
	params->still = still;
	params->times = times;
	params->fork = forks;
	params->thread = thread;
	return (params);
}
