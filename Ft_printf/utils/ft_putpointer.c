/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:36:44 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/12 17:30:45 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	len += ft_putchar(hex[ptr % 16]);
	return (len);
}
