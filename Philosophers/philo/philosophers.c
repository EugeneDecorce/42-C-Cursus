/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:52:13 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/02 13:53:49 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_threads(t_list *threads, int len)
{
	t_list	*tmp;
	int		i;

	tmp = threads;
	i = 0;
	while (tmp && i < len)
	{
		if (i < len - 1)
			tmp = threads->next;
		free(threads);
		if (i < len - 1)
			threads = tmp;
		i++;
	}
}

void	free_forks(t_fork *forks, int len)
{
	t_fork	*tmp;
	int		i;

	tmp = forks;
	i= 0;
	while (tmp && i < len)
	{
		if (i < len - 1)
			tmp = forks->next;
		free(forks);
		if (i < len - 1)
			forks = tmp;
		i++;
	}
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
	while (1)
	{
		if (!still)
			break;
		apply_each(&still, threads, forks, times);
		if (!still)
			break;
		apply_each(&still, threads, forks, null_times());
	}
	free_threads(threads, nb);
	destroy_forks_mutexes(forks);
	free_forks(forks, nb);
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
