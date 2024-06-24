/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:41:29 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/24 14:07:46 by edecorce         ###   ########.fr       */
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

int	global_arg_len(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			i++;
		if (str[i - 1] >= '0' && str[i - 1] <= '9')
			count++;
		if (str[i] && !(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			return (0);
	}
	return (count);
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

int	is_stack_valid(int *argc, char ***argv, int *is_global_arg)
{
	int	i;
	int	j;

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
	i = 0;
	while (i < *argc)
	{
		if (!is_int((*argv)[i]))
			return (0);
		j = 0;
		if (!is_stack_valid2(&j, i, *argv))
			return (0);
		i++;
	}
	return (1);
}
