/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:02:43 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/07 00:10:05 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stddef.h>

struct s_data;

typedef struct s_fork
{
	int				id;
	int				is_taken;
	pthread_mutex_t	mutex;
} t_fork;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	int				delay;
	u_int64_t		death_time;
	u_int64_t		eating_time;
	u_int64_t		sleeping_time;
	int				total_meals;
	int				total_philos;
	int				total_forks;
	u_int64_t		last_meal;
	pthread_t		thread;
	struct s_data	*data;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	meals_eaten_mutex;
} t_philo;

typedef struct s_data
{
	pthread_t		thread;
	u_int64_t		start_time;
	struct s_fork	*forks;
	struct s_philo	*philos;
	int				done;
	pthread_mutex_t	mutex;
	pthread_mutex_t	write;
} t_data;


u_int64_t	get_time(void);
int			ft_atoi(char *str);
void			*routine(void	*arg);
int	are_args_valid(char **args);
void	threads_init(t_data *datas);
void	threads_deinit(t_data *datas);
t_data	*data_modelling(int total_philos, char **argv);

#endif /* PHILOSOPHERS_H */