/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:25:07 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/20 08:17:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	trim_to_sign(char *str, int *sign, int *i)
{
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

void	trim_to_exitcode(long long unsigned int *exit_code, int *start_index, int *i, char *str)
{
	*start_index = *i;
	while (ft_isdigit(str[*i]))
	{
		*exit_code = *exit_code * 10 + (str[*i] - '0');
		(*i)++;
	}
	while (isspace(str[*i]))
		(*i)++;
}

int	atoi_exit_specific(char *str, int *error_code)
{
	unsigned long long	exit_code = 0;
	int					start_index = 0;
	int					sign = 1;
	int					i = 0;

	exit_code = 0;
	start_index = 0;
	sign = 1;
	i = 0;
	trim_to_sign(str, &sign, &i);
	trim_to_exitcode(&exit_code, &start_index, &i, str);
	if (str[i] != '\0' || i - start_index > 20 || 
		(sign == -1 && exit_code - 1 > LONG_MAX) || 
		(sign == 1 && exit_code > LONG_MAX))
	{
		*error_code = 1;
	}
	else
	{
		*error_code = 0;
	}
	return (int)((exit_code * sign) % 256);
}

void	ft_exit(t_utils *data, char **args)
{
	int	exit_code;
	int	error_code;

	exit_code = 0;
	error_code = 0;
	if (args[1])
	{
		exit_code = atoi_exit_specific(args[1], &error_code);
		if (error_code)
		{
			printf("exit: %s: numeric argument required\n", args[1]);
			free_data(data, NULL, 2);
		}
	}
	if (args[1] && args[2])
	{
		printf("exit: too many arguments\n");
		data->exit_code = 1;
		return ;
	}
	else if (!args[1])
		free_data(data, NULL, data->exit_code);
	free_data(data, NULL, exit_code);
}
