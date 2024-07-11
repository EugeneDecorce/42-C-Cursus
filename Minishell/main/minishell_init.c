/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:21:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/10 18:46:29 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	minishell_init(char **input)
{
	char	*trimmed_input;
	char	*env_input;

	add_history(*input);
	trimmed_input = ft_strtrim(*input);
	free(*input);
	if (trimmed_input == NULL)
		exit(1);
	env_input = ft_fetchenv(trimmed_input);
	free(trimmed_input);
	if (env_input == NULL)
		exit(1);
	*input = env_input;
}

//char	*unquoted_input;
	
// unquoted_input = remove_quotes(env_input);
// free(env_input);
// if (unquoted_input == NULL)
// 	exit(1);