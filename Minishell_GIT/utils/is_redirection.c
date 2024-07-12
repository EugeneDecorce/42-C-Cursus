/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:52:19 by user              #+#    #+#             */
/*   Updated: 2024/07/11 16:52:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	is_redirection(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if ((input[i] == '<' || input[i] == '>') && !is_in_quote(input, i))
			return (1);
		i++;
	}
	return (0);
}
