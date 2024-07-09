/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:10:27 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/09 16:37:14 by edecorce         ###   ########.fr       */
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

void	input_manager(char *input)
{
	if (invalid_command(input) || pipes_errors(input)
		|| backward_redirection_errors(input)
		|| forward_redirection_errors(input))
		return ;
	else if (check_command(input, "pwd"))
		ft_pwd();
	else if (check_command(input, "exit"))
		ft_exit(input);
	else if (check_command(input, "env"))
		ft_env();
	else if (is_quotes(input) || (!is_pipe(input)
			&& ((ft_strncmp(input, "echo", 4) == 0 && !input[4])
				|| (ft_strncmp(input, "echo", 4) == 0
					&& ft_contains("> <", 0, 2, input[4])))))
		ft_echo(input);
	else if (check_command(input, "cd"))
		ft_cd(input);
	else if (check_command(input, "export"))
		ft_export(input);
	else if (check_command(input, "unset"))
		ft_unset(input);
	else if (is_pipe(input))
		exec_command_with_pipes(input, 0);
	else
		handle_single_command(input, 0, -1);
}
