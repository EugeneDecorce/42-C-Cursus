/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:20:21 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/02 13:56:53 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>

long long	get_current_time_ms(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return ((long long) time.tv_sec * 1000LL
		+ (long long) time.tv_usec / 1000LL);
}
