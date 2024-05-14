/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:09:13 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/09 00:09:48 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	i = 0;
	if (dst_cpy == src_cpy)
		return (dst);
	while (i < len)
	{
		if (dst_cpy < src_cpy)
			dst_cpy[i] = src_cpy[i];
		else
			dst_cpy[len - 1 - i] = src_cpy[len - 1 - i];
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>

int main()
{
	char arr[] = "Hello, World!";
	ft_memmove(&arr[0], &arr[2], 5);
	printf("%s\n", arr);
	return (0);
}*/