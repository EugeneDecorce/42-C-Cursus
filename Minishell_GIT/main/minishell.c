/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:11:53 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 20:59:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(void)
{
	t_util	var;

	ft_cmd_status(0);
	while (1)
	{
		signal_constructor();
		var.input = readline("minishell: ");
		var.freed = 0;
		if (!var.input)
		{
			exit(0);
			continue ;
		}
		if (is_empty_string(var.input) || !var.input[0])
		{
			ft_cmd_status(0);
			free(var.input);
		}
		else
		{
			signal_constructor2();
			minishell_init(&var);
			input_manager(&var);
		}
	}
}

int	main(void)
{
	setenv("PATH",
		"/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games", 1);
	minishell();
	return (0);
}
