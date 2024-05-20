/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:03:42 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/16 14:26:24 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_len2(int nb)
{
	int	len;

	len = 1;
	while (nb >= 10)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long int	nb;
	int			len;

	nb = n;
	len = 0;
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	len += get_len2(nb);
	return (len);
}
