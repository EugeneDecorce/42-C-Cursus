/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:11:53 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/10 23:17:35 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(void)
{
	char	*input;

	ft_cmd_status(0);
	while (1)
	{
		signal_constructor();
		input = readline("minishell: ");
		if (!input)
		{
			exit(0);
			continue ;
		}
		if (is_empty_string(input) || !input[0])
		{
			ft_cmd_status(0);
			free(input);
		}
		else
		{
			signal_constructor2();
			minishell_init(&input);
			input_manager(input);
			free(input);
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
