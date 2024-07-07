/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:10:56 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/06 20:31:59 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	handle_solo_philo()
{
	printf("Here");
}

void	philosophers(int total_philos, char **argv)
{
	t_data	*datas;

	datas = data_modelling(total_philos, argv);
	if (datas == NULL)
		return ;
	threads_init(datas);
	threads_deinit(datas);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		argv++;
		if (!are_args_valid(argv))
			return (1);
		else
			philosophers(ft_atoi(argv[0]), argv);
	}
	else
	{
		printf("Invalid number of arguments, expected input:\n");
		printf("Note: time in milliseconds.\n");
		printf("1 - number_of_philosophers (mandatory)\n");
		printf("2 - time_to_die (mandatory)\n");
		printf("3 - time_to_eat (mandatory)\n");
		printf("4 - time_to_sleep (mandatory)\n");
		printf("5 - number_of_times_each_philosopher_must_eat (optional)\n");
	}
	return (0);
}
