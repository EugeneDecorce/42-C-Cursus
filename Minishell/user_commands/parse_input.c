/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:27:09 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/08 23:02:39 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

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

char	**parse_user_input(char *input)
{
	char	**args;
	char	*arg;
	int		num_args;

	args = malloc(MAX_ARGS * sizeof(char *));
	if (!args)
	{
		perror("minishell: malloc error");
		exit(EXIT_FAILURE);
	}
	num_args = 0;
	arg = ft_strtok(input, " \t\n");
	while (arg != NULL)
	{
		args[num_args++] = arg;
		arg = ft_strtok(NULL, " \t\n");
	}
	args[num_args] = NULL;
	return (args);
}
