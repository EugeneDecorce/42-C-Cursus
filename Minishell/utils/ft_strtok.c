/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:01:56 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/08 23:04:26 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*lasts;
	char		*start;
	char		*end;

	if (str)
		start = str;
	else
		start = lasts;
	if (!start)
		return (NULL);
	start += ft_strspn(start, delim);
	if (*start == '\0')
	{
		lasts = NULL;
		return (NULL);
	}
	end = start + ft_strcspn(start, delim);
	if (*end != '\0')
	{
		*end = '\0';
		lasts = end + 1;
	}
	else
		lasts = NULL;
	return (start);
}
