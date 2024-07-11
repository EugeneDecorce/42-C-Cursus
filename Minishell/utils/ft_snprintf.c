/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:12:38 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/09 13:35:58 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = vsnprintf(str, size, format, args);
	va_end(args);
	return (ret);
}
