/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:01:44 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/07 00:09:54 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#define LOCK_RETRY_INTERVAL 1000 
int	next_id(t_philo *philo)
{
	if (philo->id == philo->total_philos - 1)
		return (0);
	return (philo->id + 1);
}
void write_message(t_data *datas, t_philo *philo, char *msg)
{
    pthread_mutex_lock(&datas->mutex); // Lock to check `datas->done`
    if (datas->done)
    {
        pthread_mutex_unlock(&datas->mutex);
        return;
    }
    pthread_mutex_unlock(&datas->mutex);

    pthread_mutex_lock(&datas->write);
    printf("%lld: %d %s\n", get_time() - datas->start_time, philo->id + 1, msg);
    pthread_mutex_unlock(&datas->write);
}

int	is_simulation_done(void *args)
{
    t_data *datas;
    int all_meals_eaten;
    int i;

    datas = (t_data *)args;

   all_meals_eaten = 1;

	for (i = 0; i < datas->philos[0].total_philos; i++)
	{
		pthread_mutex_lock(&datas->philos[i].last_meal_mutex);
		if (get_time() - datas->philos[i].last_meal > datas->philos[i].death_time)
		{
			pthread_mutex_unlock(&datas->philos[i].last_meal_mutex);
			write_message(datas, &datas->philos[i], "has died");
			return (1);
		}
		pthread_mutex_unlock(&datas->philos[i].last_meal_mutex);

		pthread_mutex_lock(&datas->philos[i].meals_eaten_mutex);
		if (datas->philos[i].total_meals == -1 || datas->philos[i].meals_eaten < datas->philos[i].total_meals)
			all_meals_eaten = 0;
		pthread_mutex_unlock(&datas->philos[i].meals_eaten_mutex);
	}

	return (all_meals_eaten);
}

int ft_usleep(u_int64_t time, t_data *datas)
{
    u_int64_t start;

    start = get_time();
    while ((get_time() - start) < time)
    {
        if (is_simulation_done(datas))
            return 1;
        usleep(time / 100);
    }
    return 0;
}

void *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;

    // Start the simulation monitoring thread
    //pthread_create(&philo->data->thread, NULL, is_simulation_done, philo->data);
    while (1)
    {
        pthread_mutex_lock(&philo->last_meal_mutex);
        if (get_time() - philo->last_meal > philo->death_time)
        {
            pthread_mutex_unlock(&philo->last_meal_mutex);
            write_message(philo->data, philo, "has died");
            return NULL;
        }
        pthread_mutex_unlock(&philo->last_meal_mutex);

        if (ft_usleep(philo->delay, philo->data))
            return NULL;

        pthread_mutex_lock(&(philo->data->forks)[philo->id].mutex);
        write_message(philo->data, philo, "has taken a fork");

        pthread_mutex_lock(&(philo->data->forks)[next_id(philo)].mutex);
        write_message(philo->data, philo, "has taken a fork");

        write_message(philo->data, philo, "is eating");

        pthread_mutex_lock(&philo->last_meal_mutex);
        philo->last_meal = get_time();
        pthread_mutex_unlock(&philo->last_meal_mutex);

        pthread_mutex_lock(&philo->meals_eaten_mutex);
        philo->meals_eaten++;
        pthread_mutex_unlock(&philo->meals_eaten_mutex);

        if (ft_usleep(philo->eating_time, philo->data))
        {
            pthread_mutex_unlock(&(philo->data->forks)[philo->id].mutex);
            pthread_mutex_unlock(&(philo->data->forks)[next_id(philo)].mutex);
            return NULL;
        }

        pthread_mutex_unlock(&(philo->data->forks)[philo->id].mutex);
        pthread_mutex_unlock(&(philo->data->forks)[next_id(philo)].mutex);

        write_message(philo->data, philo, "is sleeping");
        if (ft_usleep(philo->sleeping_time, philo->data))
            return NULL;

        write_message(philo->data, philo, "is thinking");
        philo->delay = 5;
    }
    // Wait for the simulation monitoring thread to finish
    //pthread_join(philo->data->thread, NULL);
    return NULL;
}