/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 03:32:04 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/25 19:55:56 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks_mutexes(t_fork *forks)
{
	t_fork	*tmp;

	tmp = forks;
	while (tmp)
	{
		pthread_mutex_init(&tmp->mutex, NULL);
		tmp = tmp->next;
		if (tmp->id == 0)
			return ;
	}
}

void	destroy_forks_mutexes(t_fork *forks)
{
	t_fork	*tmp;

	tmp = forks;
	while (tmp)
	{
		pthread_mutex_destroy(&tmp->mutex);
		tmp = tmp->next;
		if (tmp->id == 0)
			return ;
	}
}

int	val(t_fork *forks, int id)
{
	t_fork	*tmp;
	int		start_id;

	tmp = forks;
	start_id = tmp->id;
	while (tmp)
	{
		pthread_mutex_lock(&tmp->mutex);
		if (tmp->next && tmp->id == id
			&& tmp->next && tmp->id != tmp->next->id)
		{
			if (tmp->taken == 0)
			{
				tmp->taken = 1;
				pthread_mutex_unlock(&tmp->mutex);
				return (1);
			}
			else if (tmp->next->taken == 0)
			{
				tmp->next->taken = 1;
				pthread_mutex_unlock(&tmp->mutex);
				return (1);
			}
			pthread_mutex_unlock(&tmp->mutex);
			return (0);
		}
		pthread_mutex_unlock(&tmp->mutex);
		tmp = tmp->next;
		if (tmp->id == start_id)
			break ;
	}
	return (0);
}

void	discharge_forks(t_fork *forks, int id)
{
	t_fork	*tmp;
	int		start_id;

	tmp = forks;
	start_id = tmp->id;
	while (tmp)
	{
		pthread_mutex_lock(&tmp->mutex);
		if (tmp->id == id)
		{
			tmp->taken = 0;
			tmp->next->taken = 0;
		}
		pthread_mutex_unlock(&tmp->mutex);
		tmp = tmp->next;
		if (tmp->id == start_id)
			break ;
	}
}
