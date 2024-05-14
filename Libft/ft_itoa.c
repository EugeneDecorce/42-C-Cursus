/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:49:38 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/11 00:21:24 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_get_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		is_negative;
	long	nb;

	nb = n;
	len = ft_get_len(nb);
	is_negative = 0;
	if (nb < 0)
	{
		is_negative = 1;
		nb *= -1;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>

int main()
{
	int n = -2147483648;
	char *str = ft_itoa(n);
	printf("%s\n", str);
	return 0;
}*/