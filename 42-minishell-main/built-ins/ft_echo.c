/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:33:45 by handler           #+#    #+#             */
/*   Updated: 2024/07/15 01:16:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	write_echo(char **args, int option, int count, int i);
void	echo_running_job(char **args, int option, int count, int i);

int	ft_echo(char **args)
{
	int		count;
	int		i;
	int	option;

	count = 0;
	while (args[count])
		++count;
	i = 1;
	option = 1;
	echo_running_job(args, option, count, i);
	return (0);
}

int	is_option(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '-')
	{
		++i;
		while (str[i] && str[i] == 'n')
			i++;
		if (i == (int)ft_strlen(str))
			return (1);
	}
	return (0);
}

void	echo_running_job(char **args, int option, int count, int i)
{
	while (args[i] && is_option(args[i]))
	{
		++i;
		option = 0;
	}
	while (i < count)
	{
		write(1, args[i], ft_strlen(args[i]));
		if (i != count - 1)
			write(1, " ", 1);
		++i;
	}
	if (option)
		write(1, "\n", 1);
}

