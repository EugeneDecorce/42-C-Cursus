/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:44:34 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/12 17:28:02 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format_specifier(char c, va_list	*arg)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(*arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*arg, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(*arg, unsigned long), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*arg, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*arg, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(*arg, int), 1));
	else if (c == 'X')
		return (ft_puthex(va_arg(*arg, int), 0));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += handle_format_specifier(str[i], &args);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>

int main()
{
	char test_char = 4;
	ft_printf("ft_printf: %c", test_char);
	printf("|printf: %c\n", test_char);

	char test_char2 = '4';
	ft_printf("ft_printf: %c", test_char2);
	printf("|printf: %c\n", test_char2);

	char *test_string = "Hello, world";
	ft_printf("ft_printf: %s", test_string);
	printf("|printf: %s\n", test_string);

	char *test_string2 = "";
	ft_printf("ft_printf: %s", test_string2);
	printf("|printf: %s\n", test_string2);

	int x = 10;
	int *test_void_pointer = &x;
	ft_printf("ft_printf: %p", test_void_pointer);
	printf("|printf: %p\n", test_void_pointer);

	int decimal_number = 123;
	ft_printf("ft_printf: %d", decimal_number);
	printf("|printf: %d\n", decimal_number);

	int integer_number = -456;
	ft_printf("ft_printf: %i", integer_number);
	printf("|printf: %i\n", integer_number);

	unsigned int unsigned_decimal_number = 789;
	ft_printf("ft_printf: %u", unsigned_decimal_number);
	printf("|printf: %u\n", unsigned_decimal_number);

	int hex_number = 3452;
	ft_printf("ft_printf: %x", hex_number);
	printf("|printf: %x\n", hex_number);

	ft_printf("ft_printf: %X", hex_number);
	printf("|printf: %X\n", hex_number);

	ft_printf("ft_printf: %%");
	printf("|printf: %%\n\n");

	int test_int = 3422;
	//char test_char3 = 'm';
	char *test_string3 = "Hello world"; 
	ft_printf("int: %d, int: %d, int: %d\n", 
	test_int, test_int, test_int);
	ft_printf("int: %d, char: %s, string: %d", 
	test_int, test_string3, test_int);
}*/