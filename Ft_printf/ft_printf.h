/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:19:22 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/12 17:29:46 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr(int n);
int	ft_tolower(int c);
int	ft_toupper(int c);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_puthex(int n, int is_lower);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putpointer(unsigned long ptr, int prefix);

#endif /* FT_PRINTF_H */