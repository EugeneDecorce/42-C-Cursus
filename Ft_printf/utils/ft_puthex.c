/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:04:46 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/16 14:36:47 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_len4(unsigned int n)
{
	int	len;

	if (n < 0)
		n *= -1;
	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int n, int is_lower)
{
	long int	nb;
	int			len;
	char		*hex_lower;
	char		*hex_upper;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 16)
		ft_puthex(nb / 16, is_lower);
	if (is_lower)
		ft_putchar(hex_lower[nb % 16]);
	else
		ft_putchar(hex_upper[nb % 16]);
	len += get_len4(n);
	return (len);
}
