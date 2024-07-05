/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:55:07 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/02 20:30:59 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

// state: 0 eating -> 1 sleeping -> 2 thinking
typedef struct s_fork
{
	int				id;
	int				taken;
	pthread_mutex_t	mutex;
	struct s_fork	*next;
}	t_fork;

typedef struct s_list
{
	int				done;
	int				id;
	int				delay;
	pthread_t		thread;
	int				state;
	int				total_forks;
	int				total_philo;
	long long		last_meal_time;
	long long		eating_since;
	long long		sleeping_since;
	int				total_meals;
	pthread_mutex_t	mutex;
	struct s_list	*next;
}	t_list;

typedef struct s_times
{
	long long		start_time;
	int				null;
	int				die;
	int				eat;
	int				sleep;
	int				meals;
}	t_times;

typedef struct s_create_thread_params
{
	long long		start_time;
	t_fork			*fork;
	t_times			times;
	t_list			*thread;
}	t_create_thread_params;

int						ft_atoi(char *str);
void					ft_putstr(char *str);
t_fork					*make_forks(int num);
long long				get_current_time_ms(void);
t_list					*make_threads(int num);
int						are_args_valid(char **args);
t_times					proccessed_args(int argc, char **argv);
t_create_thread_params	*generate_create_thread_params(t_fork *forks,
							t_times times, t_list *thread);

t_times					null_times(void);
void					*thread_routine(void *args);
void					discharge_forks(t_fork *forks, int id, int total_philo);
void					destroy_forks_mutexes(t_fork *forks);
int						all_meals_eaten(t_list *thread, int total);
int						val(t_fork *forks, int id, int total_philo);
void					apply_each(t_list *threads,
							t_fork *forks, t_times times);

int						is_simulation_done(t_list *threads);

#endif /* PHILOSOPHERS_H */

// t_list *tmp2 = threads;
// 	int start_index = tmp->id;
// 	while (tmp2)
// 	{
// 		printf("Ok %d", tmp2->id);
// 		tmp2 = tmp2->next;
// 		if (tmp2->id == start_index)
// 			break ;
// 	}