/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:28:57 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/16 10:40:34 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//if (!s) --> Original function does not check that
	//	return (NULL);
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char) c)
		s++;
	if (*s == (char) c)
		return ((char *)s);
	return (NULL);
}
