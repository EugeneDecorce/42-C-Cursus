/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:18:51 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 19:20:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h" 

void	sigint_handler2(int signum)
{
	if (signum == SIGQUIT)
	{
		write(2, "exit\n", 5);
		exit(130);
	}
}

void	sigint_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		write(2, "exit\n", 5);
		exit(130);
	}
}
