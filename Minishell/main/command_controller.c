/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:10:27 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 00:30:01 by edecorce         ###   ########.fr       */
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

int	is_pipe(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '|' && !is_in_quote(input, i))
			return (1);
		i++;
	}
	return (0);
}

int	is_quotes(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '\"')
			return (1);
		i++;
	}
	return (0);
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
	if (ft_subchar(input, "| ||"))
		printf("bash: parse error near `||'\n");
	else if (ft_subchar(input, "| |") || ft_subchar(input, "|| |")
		|| ft_subchar(input, "|||"))
		printf("bash: parse error near `|'\n");
	else
		return (0);
	ft_cmd_status(1);
	return (1);
}

// else if (ft_strncmp(input, "echo <<", 7) && (is_quotes(input)
// 		|| (!is_pipe(input) && ((ft_strncmp(input, "echo", 4) == 0
// 					&& !input[4]) || (ft_strncmp(input, "echo", 4) == 0
// 					&& ft_contains("> <", 0, 2, input[4]))))))
// 	ft_echo(input);


void	input_manager(char *input)
{
	if (invalid_command(input) || pipes_errors(input)
		|| backward_redirection_errors(input)
		|| forward_redirection_errors(input))
		return ;
	else if (check_command(input, "exit"))
		ft_exit(input);
	else if (check_command(input, "export"))
		ft_export(input);
	else if (check_command(input, "cd"))
		ft_cd(input);
	// else if (!ft_contains(input, 0, ft_strlen(input) - 1, '|') && !ft_contains(input, 0, ft_strlen(input) - 1, '<') && !ft_contains(input, 0, ft_strlen(input) - 1, '>') && ft_strncmp(input, "echo", 4) == 0)
	// 	ft_echo(input);
	else if (check_command(input, "unset"))
		ft_unset(input);
	else
	{
		printf("%d", is_pipe(input));
		exec_command(input);
	}
}
