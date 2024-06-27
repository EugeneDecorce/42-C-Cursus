/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:41:29 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/25 09:21:44 by edecorce         ###   ########.fr       */
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
	int		i;
	long	nb;

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
	nb = ft_atoi_long(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}

void	free_map(char **map, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	process_global_arg(int *argc, char ***argv, int *is_global_arg)
{
	if (!(*argv)[1] && ft_contains((*argv)[0], ' '))
	{
		*is_global_arg = 1;
		if (!global_arg_len((*argv)[0]))
			return (0);
		if (convert_global_var((*argv)[0]) == NULL)
			return (0);
		*argc = global_arg_len((*argv)[0]);
		*argv = convert_global_var((*argv)[0]);
	}
	return (1);
}

int	is_stack_valid(int *argc, char ***argv, int *is_global_arg)
{
	int	i;
	int	j;

	if (!process_global_arg(argc, argv, is_global_arg))
		return (0);
	i = 0;
	j = 0;
	while (i < *argc)
	{
		if (!is_int((*argv)[i]))
			return (0);
		while (j < i)
		{
			if (ft_strcmp((*argv)[i], (*argv)[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
