/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:21:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 15:07:55 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	minishell_init(t_util *var)
{
	char	*trimmed_input;
	char	*env_input;

	add_history(var->input);
	trimmed_input = ft_strtrim(var->input);
	free(var->input);
	if (trimmed_input == NULL)
		exit(1);
	env_input = ft_fetchenv(trimmed_input);
	free(trimmed_input);
	if (env_input == NULL)
		exit(1);
	var->input = env_input;
}
