/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:38:20 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/06 14:12:15 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

u_int64_t	get_time(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return ((u_int64_t) time.tv_sec * 1000LL
		+ (u_int64_t) time.tv_usec / 1000LL);
}

int	ft_atoi(char *str)
{
	int	i;
	int	time;

	if (str == NULL)
		return (-1);
	i = 0;
	time = str[i] - '0';
	i++;
	while (str[i])
	{
		time = (time * 10) + str[i] - '0';
		i++;
	}
	return (time);
}

