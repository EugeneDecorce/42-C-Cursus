/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:57:13 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/22 01:38:14 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit_count;

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	c;
	static int	value;

	(void) context;
	if (!g_bit_count)
		c = 0;
	if (!g_bit_count)
		value = 128;
	if (signum == SIGUSR1)
		c += value;
	g_bit_count++;
	value /= 2;
	if (g_bit_count == 8)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		ft_putchar(c);
		g_bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	g_bit_count = 0;
	ft_putint(getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		sleep(1);
	return (0);
}
