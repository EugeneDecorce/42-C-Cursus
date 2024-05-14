/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:49:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/09 00:06:37 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	unsigned int	i;
	size_t			total_size;

	total_size = count * size;
	str = malloc(total_size);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		str[i] = 0;
		i++;
	}
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