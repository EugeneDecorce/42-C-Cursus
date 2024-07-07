/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_modelling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:29:04 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/06 13:44:17 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
			printf("At least one argument is not valid!\nPlease ");
			printf("check that all arguments are positive numbers.\n");
			return (0);
		}
		if (ft_strlen(args[i]) > 9)
		{
			printf("The time set seems very large, it is exceeding ");
			printf("our limit (999_999_999 milliseconds => 278 hours)\n");
			printf("Try with smaller numbers!");
			return (0);
		}
		i++;
	}
	return (1);
}
