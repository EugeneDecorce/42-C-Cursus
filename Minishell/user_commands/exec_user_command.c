/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_user_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:57:53 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/08 22:51:48 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	split_commands(int *in_fd, char *input, char *commands[])
{
	int		num_commands;
	char	*command;

	*in_fd = STDIN_FILENO;
	num_commands = 0;
	command = ft_strtok(input, "|");
	while (command != NULL)
	{
		commands[num_commands++] = command;
		command = ft_strtok(NULL, "|");
	}
	commands[num_commands] = NULL;
	return (num_commands);
}

int	handle_single_command_logic(char **command_path, char **args)
{
	if (args[0][0] == '/' || strchr(args[0], '/'))
	{
		*command_path = get_command_path(args[0]);
		if (!(*command_path))
		{
			printf("minishell: %s: No such file or directory\n", args[0]);
			return (1);
		}
	}
	else
	{
		*command_path = find_user_command(args[0]);
		if (!(*command_path))
		{
			printf("minishell: %s: command not found\n", args[0]);
			ft_cmd_status(127);
			return (1);
		}
	}
	return (0);
}
