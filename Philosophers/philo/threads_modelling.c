/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_modelling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:58:35 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/07 00:04:23 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void threads_init(t_data *datas)
{
    int i;


    // Start the philosopher threads
    i = 0;
    while (i < datas->philos[0].total_philos) // Use correct access to total_philos
    {
        pthread_create(&datas->philos[i].thread, NULL, routine, &datas->philos[i]);
        i++;
    }

    // Wait for the philosopher threads to finish
    i = 0;
    while (i < datas->philos[0].total_philos) // Use correct access to total_philos
    {
        pthread_join(datas->philos[i].thread, NULL);
        i++;
    }

}

void	threads_deinit(t_data *datas)
{
	int	i;

	i = 0;
	while (i < datas->philos[0].total_philos)
	{
		pthread_mutex_destroy(&datas->forks[i].mutex);
		i++;
	}
	free(datas->forks);
	free(datas->philos);
	free(datas);
}