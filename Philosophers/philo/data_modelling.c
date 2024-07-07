/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_modelling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:39:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/06 20:25:00 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	data_mallocation(int total_philos, t_fork **forks, t_philo **philos, t_data **datas)
{
	*forks = (t_fork *) malloc(total_philos * sizeof(t_fork));
	if (*forks == NULL)
		return (0);
	*philos = (t_philo *) malloc(total_philos * sizeof(t_philo));
	if (*philos == NULL)
		return (free(*forks), 0);
	*datas = (t_data *) malloc(sizeof(t_data));
	if (*datas == NULL)
		return (free(*forks), free(*philos), 0);
	return (1);
}

void	forks_init(int total_philos, t_fork **forks)
{
	int	i;

	i = 0;
	while (i < total_philos)
	{
		(*forks)[i].id = i;
		(*forks)[i].is_taken = 0;
		pthread_mutex_init(&(*forks)[i].mutex, NULL);
		i++;
	}
}

void	philos_init(int total_philos, char **argv, t_philo **philos, t_data *datas)
{
	int	i;

	i = 0;
	while (i < total_philos)
	{
		(*philos)[i].id = i;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].delay = (i % 2) * 5;
		(*philos)[i].death_time = (u_int64_t) ft_atoi(argv[1]);
		(*philos)[i].eating_time = (u_int64_t) ft_atoi(argv[2]);
		(*philos)[i].sleeping_time = (u_int64_t) ft_atoi(argv[3]);
		(*philos)[i].total_meals = (u_int64_t) ft_atoi(argv[4]);
		(*philos)[i].total_philos = total_philos;
		(*philos)[i].last_meal = datas->start_time;
		(*philos)[i].data = datas;
		i++;
	}
}

void	datas_init(t_data **datas, t_fork **forks, t_philo **philos, u_int64_t start_time)
{
	(*datas)->start_time = start_time;
	(*datas)->forks = *forks;
	(*datas)->philos = *philos;
	(*datas)->done = 0;
	pthread_mutex_init(&(*datas)->write, NULL);
}

t_data	*data_modelling(int total_philos, char **argv)
{
	u_int64_t		start_time;
	t_fork	*forks;
	t_philo	*philos;
	t_data	*datas;

	if (!data_mallocation(total_philos, &forks, &philos, &datas))
		return (NULL);
	start_time = get_time();
	forks_init(total_philos, &forks);
	datas_init(&datas, &forks, &philos, start_time);
	philos_init(total_philos, argv, &philos, datas);

	return (datas);
}
