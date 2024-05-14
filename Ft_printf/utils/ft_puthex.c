/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:04:46 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/12 16:15:48 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(int n, int is_lower)
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
		len += ft_putchar(hex_lower[nb % 16]);
	else
		len += ft_putchar(hex_upper[nb % 16]);
	return (len);
}
