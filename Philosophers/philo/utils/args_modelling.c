/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_modelling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:36:39 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/25 14:03:06 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_times	proccessed_args(int argc, char **argv)
{
	t_times	times;

	times.start_time = get_current_time_ms();
	times.null = 0;
	times.die = ft_atoi(argv[1]);
	times.eat = ft_atoi(argv[2]);
	times.sleep = ft_atoi(argv[3]);
	if (argc == 6)
		times.meals = ft_atoi(argv[4]);
	else
		times.meals = -1;
	return (times);
}

t_times	null_times(void)
{
	t_times	times;

	times.null = 1;
	return (times);
}
