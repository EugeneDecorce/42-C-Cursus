/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partial_signals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:20:46 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/13 09:41:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	clear_rl_line(void)
{
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	handle_sigint(int signum)
{
	(void) signum;
	printf("\n");
	clear_rl_line();
	if (g_signal_pid == 0)
		rl_redisplay();
}

void	handle_sigsegv(int signum)
{
	(void) signum;
	write(2, "Segmentation fault\n", 19);
	exit(11);
}

void	handle_sigabrt(int signum)
{
	(void) signum;
	write(1, "abort\n", 6);
}

void	handle_sigquit(int signum)
{
	(void) signum;
	if (g_signal_pid != 0)
	{
		write(1, "Quit\n", 6);
		ft_cmd_status(131);
	}
}
