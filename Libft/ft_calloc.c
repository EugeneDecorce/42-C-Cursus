/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:49:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/16 10:40:55 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <limits.h>

void	*ft_memset2(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			total_size;

	if (count != 0 && size != 0 && (count > UINT_MAX / size))
		return (NULL);
	total_size = count * size;
	str = malloc(total_size);
	if (str == NULL)
		return (NULL);
	ft_memset2(str, 0, total_size);
	return (str);
}

/*#include <stdio.h>

int main()
{
	char *str;
	int i;

	i = 0;
	str = (char *)ft_calloc(10, sizeof(char));
	while (i < 10)
	{
		printf("%c", str[i] + 48);
		i++;
	}
	return (0);
}*/