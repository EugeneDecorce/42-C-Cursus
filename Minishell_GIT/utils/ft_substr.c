/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:04:26 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/09 14:57:18 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

char	*ft_substr(char *str, int from, int to)
{
	char	*substr;
	int		i;

	substr = (char *) malloc((to - from + 2) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (from + i <= to && str[from + i])
	{
		substr[i] = str[from + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
