/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:30:52 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/16 14:19:31 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_len3(unsigned int nb)
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

int	ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	ft_putchar(n % 10 + '0');
	return (get_len3(n));
}
