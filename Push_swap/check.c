/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:41:29 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/20 19:25:20 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/t_list.h"
#include "headers/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (ft_strlen(str) > 11)
		return (0);
	if (ft_strlen(str) == 11 && str[0] != '-')
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	}
	if (ft_strlen(str) == 11 && str[0] == '-')
	{
		if (ft_strcmp(str, "-2147483648") > 0)
			return (0);
	}
	return (1);
}

int	is_stack_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		if (!is_int(argv[i]))
			return (0);
		j = 0;
		while (j < i)
		{
			if (j != i && ft_strcmp(argv[i], argv[j]) == 0)
			{
				printf("%s", argv[i]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
