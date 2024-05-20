/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:36:44 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/16 14:06:50 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_len(unsigned long ptr)
{
	int	len;

	len = 1;
	while (ptr >= 16)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

int	ft_putpointer(unsigned long ptr, int prefix)
{
	char	*hex;
	int		len;

	len = 0;
	if (prefix)
	{
		len += ft_putstr("0x");
		prefix = 0;
	}
	hex = "0123456789abcdef";
	if (ptr >= 16)
		ft_putpointer(ptr / 16, prefix);
	ft_putchar(hex[ptr % 16]);
	len += get_len(ptr);
	return (len);
}
