/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:10:27 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 20:48:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	command_not_found(char *input)
{
	int	i;

	i = 0;
	printf("Bash: ");
	while (input[i] && input[i] != ' ')
	{
		printf("%c", input[i]);
		i++;
	}
	printf(":command not found\n");
	ft_cmd_status(127);
}

int	check_command(char *input, char *test)
{
	int	i;

	i = ft_strlen(test);
	return ((ft_strncmp(input, test, i) == 0 && !input[i])
		|| (ft_strncmp(input, test, i) == 0 && input[i] == ' '));
}

int	invalid_command(char *input)
{
	int	i;

	i = 0;
	while (input[i] && input[i] != ' ')
	{
		if (input[i] == '\'' || input[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

int	pipes_errors(char *input)
{
	if (ft_subchar(input, "||"))
		printf("\'||\' not to be implemented\n");
	else  if (ft_subchar(input, "| ||"))
		printf("bash: parse error near `||'\n");
	else if (ft_subchar(input, "| |") || ft_subchar(input, "|| |")
		|| ft_subchar(input, "|||"))
		printf("bash: parse error near `|'\n");
	else
		return (0);
	ft_cmd_status(1);
	return (1);
}

void	input_manager(t_util *var)
{
	if (invalid_command(var->input) || pipes_errors(var->input)
		|| backward_redirection_errors(var->input)
		|| forward_redirection_errors(var->input))
		return ;
	else if (check_command(var->input, "exit"))
		ft_exit(var->input);
	else if (check_command(var->input, "export"))
		ft_export(var->input);
	else if (check_command(var->input, "cd"))
		ft_cd(var->input);
	else if (check_command(var->input, "unset"))
		ft_unset(var->input);
	else
	{
		exec_command(var);
		ft_freemap(var->args, var->size);
	}
	free(var->input);
}
