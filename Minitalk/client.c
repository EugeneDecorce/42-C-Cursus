/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:57:27 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/22 01:45:50 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char c)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (c >> j & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		j--;
	}
}

void	send_message(pid_t pid, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		send_signals(pid, str[i]);
		i++;
	}
	send_signals(pid, 0);
}

int	is_pid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	(void) signum;
	(void) context;
	ft_putstr("Message well received by server (");
	ft_putint(info->si_pid);
	ft_putstr(")!\n");
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	if (argc == 3)
	{
		if (is_pid_number(argv[1]))
		{
			ft_putstr("Source of failure: <PID_NOT_NUMBER>\n");
			ft_putstr("Your PID contains at least one non numeric character\n");
			return (1);
		}
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
		sigaction(SIGUSR1, &sa, 0);
		send_message(ft_atoi(argv[1]), argv[2]);
	}
	else
	{
		ft_putstr("Source of failure: <WRONG_ENTRY>\n");
		ft_putstr("Correct entry example: ./client <server_pid> ");
		ft_putstr("(unsigned int) <message> (char *)\n");
		return (1);
	}
	return (0);
}
