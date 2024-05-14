/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 03:33:49 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/29 00:29:13 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	all_meals_eaten(t_list *thread, int total)
{
	t_list	*tmp;
	int		start_id;

	tmp = thread;
	start_id = tmp->id;
	while (tmp)
	{
		if (tmp->total_meals < total)
			return (0);
		tmp = tmp->next;
		if (tmp == NULL || tmp->id == start_id)
			break ;
	}
	return (1);
}

void	handle_state(t_create_thread_params *params, long long time)
{
	if (params->thread->state == 2 && val(params->fork, params->thread->id))
	{
		printf("%lld %d has taken a fork\n", time, params->thread->id + 1);
		printf("%lld %d is eating\n", time, params->thread->id + 1);
		params->thread->eating_since = time;
		params->thread->state = 0;
	}
	if (params->thread->state == 0
		&& ((time - params->thread->eating_since)
			>= (long long) params->times.eat))
	{
		discharge_forks(params->fork, params->thread->id);
		printf("%lld %d is sleeping\n", time, params->thread->id + 1);
		params->thread->total_meals += 1;
		params->thread->last_meal_time = time;
		params->thread->sleeping_since = time;
		params->thread->state = 1;
	}
	if (params->thread->state == 1
		&& (time - params->thread->sleeping_since)
		>= (long long) params->times.sleep)
	{
		printf("%lld %d is thinking\n", time, params->thread->id + 1);
		params->thread->state = 2;
	}
}

void	*thread_routine(void *args)
{
	t_create_thread_params	*params;
	long long				current_time;

	params = (t_create_thread_params *) args;
	current_time = get_current_time_ms();
	if (params->times.meals > -1
		&& all_meals_eaten(params->thread, params->times.meals))
	{
		*params->still = 0;
		free(params);
		return (NULL);
	}
	if (params->thread->state != 0
		&& (current_time - params->thread->last_meal_time)
		>= (long long) params->times.die)
	{
		printf("%lld %d died\n", current_time, params->thread->id + 1);
		*params->still = 0;
		free(params);
		return (NULL);
	}
	handle_state(params, current_time);
	free(params);
	return (NULL);
}

void	apply_each(int *still, t_list *threads, t_fork *forks, t_times times)
{
	t_list					*tmp;
	t_create_thread_params	*params;

	tmp = threads;
	while (tmp)
	{
		if (times.null)
			pthread_join(tmp->thread, NULL);
		else
		{
			params = generate_create_thread_params(forks, times, tmp, still);
			if (params == NULL)
			{
				*still = 0;
				free(params);
				return ;
			}
			pthread_create(&tmp->thread, NULL, thread_routine, (void *) params);
		}
		tmp = tmp->next;
		if (tmp->id == 0)
			return ;
	}
}
