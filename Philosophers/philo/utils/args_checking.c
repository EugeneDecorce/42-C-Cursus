/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:57:56 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/29 00:33:34 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	are_args_valid(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]))
		{
			ft_putstr("At least one argument is not valid!\nPlease ");
			ft_putstr("check that all arguments are positive numbers.\n");
			return (0);
		}
		if (ft_strlen(args[i]) > 9)
		{
			ft_putstr("The time set seems very large, it is exceeding ");
			ft_putstr("our limit (999_999_999 milliseconds => 278 hours)\n");
			ft_putstr("Try with smaller numbers!");
			return (0);
		}
		i++;
	}
	return (1);
}
