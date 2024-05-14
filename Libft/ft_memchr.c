/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:33:59 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/09 00:02:52 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;

	str = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*str == uc)
			return (str);
		str++;
	}
	return (0);
}
