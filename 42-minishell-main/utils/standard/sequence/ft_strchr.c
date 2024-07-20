/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:57:37 by handler           #+#    #+#             */
/*   Updated: 2022/11/09 13:54:42 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../main/minishell.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int	i;

	i = -1;
	while (string[++i])
		if (string[i] == (unsigned char)searchedChar)
			return ((char *)&string[i]);
	if (string[i] == (unsigned char)searchedChar)
		return ((char *)&string[i]);
	return (NULL);
}
