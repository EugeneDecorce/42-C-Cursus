/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:08:43 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/08 23:04:40 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	env_delim(char *str, int i)
{
	while (str[i])
	{
		if (!is_in_quote(str, i) && !(ft_isalpha(str[i])
				|| (str[i] >= '0' && str[i] <= '9' ) || str[i] == '?'))
			return (i - 1);
		i++;
	}
	return (i - 1);
}

int	env_delim_noq(char *str, int i)
{
	while (str[i])
	{
		if (!(ft_isalpha(str[i]) || (str[i] >= '0'
					&& str[i] <= '9') || str[i] == '?'))
			return (i - 1);
		i++;
	}
	return (i - 1);
}
