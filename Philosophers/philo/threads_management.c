/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 03:33:49 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/02 20:35:13 by edecorce         ###   ########.fr       */
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

void	handle_state(t_create_thread_params *params, long long time, long long start_time)
{
	pthread_mutex_lock(&params->thread->mutex);
	if (params->thread->state == 2)
	{
		if ((time - params->thread->last_meal_time >= params->thread->delay) && val(params->fork, params->thread->id, params->thread->total_philo))
		{
			printf("%lld %d has taken a fork\n", time - start_time, params->thread->id + 1);
			params->thread->delay = 0;
			params->thread->total_forks += 1;
		}
		if (params->thread->total_forks == 2)
		{
			printf("%lld %d is eating\n", time - start_time, params->thread->id + 1);
			params->thread->last_meal_time = time;
			params->thread->eating_since = time;
			params->thread->state = 0;
			params->thread->total_forks = 0;
		}
	}
	if (params->thread->state == 0
		&& ((time - params->thread->eating_since)
			>= (long long) params->times.eat))
	{
		discharge_forks(params->fork, params->thread->id, params->thread->total_philo);
		printf("%lld %d is sleeping\n", time - start_time, params->thread->id + 1);
		params->thread->total_meals += 1;
		params->thread->sleeping_since = time;
		params->thread->state = 1;
	}
	if (params->thread->state == 1
		&& (time - params->thread->sleeping_since)
		>= (long long) params->times.sleep)
	{
		params->thread->delay = 5;
		printf("%lld %d is thinking\n", time - start_time, params->thread->id + 1);
		params->thread->state = 2;
	}
	pthread_mutex_unlock(&params->thread->mutex);
}

void	*thread_routine(void *args)
{
	t_create_thread_params	*params;
	long long				current_time;

	params = (t_create_thread_params *) args;
	current_time = get_current_time_ms();
	pthread_mutex_lock(&params->thread->mutex);
	if (params->times.meals > -1
		&& all_meals_eaten(params->thread, params->times.meals))
	{
		params->thread->done = 1;
		pthread_mutex_unlock(&params->thread->mutex);
		free(params);
		return (NULL);
	}
	if (params->thread->state != 0
		&& (current_time - params->thread->last_meal_time)
		>= (long long) params->times.die)
	{
		printf("%lld %d died\n", current_time - params->start_time, params->thread->id + 1);
		params->thread->done = 1;
		pthread_mutex_unlock(&params->thread->mutex);
		free(params);
		return (NULL);
	}
	pthread_mutex_unlock(&params->thread->mutex);
	handle_state(params, current_time, params->start_time);
	free(params);
	return (NULL);
}

void	apply_each(t_list *threads, t_fork *forks, t_times times)
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
			params = generate_create_thread_params(forks, times, tmp);
			if (params == NULL)
			{
				threads->done = 1;
				free(params);
				return ;
			}
			params->start_time = times.start_time;
			pthread_create(&tmp->thread, NULL, thread_routine, (void *) params);
			if (is_simulation_done(threads))
			{
				pthread_detach(tmp->thread);
				return ;
			}
			pthread_detach(tmp->thread);
		}
		tmp = tmp->next;
		if (tmp->id == 0)
			return ;
	}
}
