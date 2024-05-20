/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:52:13 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/19 21:45:25 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_threads(t_list *threads)
{
	t_list	*tmp;

	while (threads)
	{
		tmp = threads;
		free(tmp);
		threads = threads->next;
	}
	free(threads);
}

void	free_forks(t_fork *forks)
{
	t_fork	*tmp;

	while (forks)
	{
		tmp = forks;
		free(tmp);
		forks = forks->next;
	}
	free(forks);
}

void	philosophers(int nb, t_times times)
{
	t_list					*threads;
	t_fork					*forks;
	int						still;

	threads = make_threads(nb);
	forks = make_forks(nb);
	init_forks_mutexes(forks);
	still = 1;
	while (still)
	{
		apply_each(&still, threads, forks, times);
		apply_each(&still, threads, forks, null_times());
	}
	free_threads(threads);
	free_forks(forks);
	destroy_forks_mutexes(forks);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		argv++;
		if (!are_args_valid(argv))
			return (1);
		else
			philosophers(ft_atoi(argv[0]), proccessed_args(argc, argv));
	}
	else
	{
		ft_putstr("Invalid number of arguments, expected input:\n");
		ft_putstr("Note: time in milliseconds.\n");
		ft_putstr("1 - number_of_philosophers (mandatory)\n");
		ft_putstr("2 - time_to_die (mandatory)\n");
		ft_putstr("3 - time_to_eat (mandatory)\n");
		ft_putstr("4 - time_to_sleep (mandatory)\n");
		ft_putstr("5 - number_of_times_each_philosopher_must_eat (optional)\n");
	}
	return (0);
}
