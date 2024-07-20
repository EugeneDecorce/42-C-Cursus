/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:27:47 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/20 08:17:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main/minishell.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	if (arr)
		free(arr);
	arr = NULL;
}


int	print_error_token(t_token *token, t_utils *data)
{
	write(2, "syntax error near unexpected token ", 35);
	write(2, "'", 1);
	if (token->next == data->token)
		write(2, "newline", 7);
	else
		write(2, token->next->str, ft_strlen(token->next->str));
	write(2, "'\n", 2);
	return (0);
}

void	free_data(t_utils *data, char *exit_msg, int exit_code)
{
	if (data->cmd)
		free_cmd(&data->cmd);
	if (data->token)
		free_token(&data->token);
	if (data->env)
		free_list(&data->env);
	if (data->pip[0] && data->pip[0] != -1)
		close(data->pip[0]);
	if (data->pip[1] && data->pip[1] != -1)
		close(data->pip[1]);
	if (exit_msg)
		printf("%s", exit_msg);
	rl_clear_history();
	if (!access(".heredoc.temp", F_OK))
		unlink(".heredoc.temp");
	if (exit_code != -1)
		exit(exit_code);
}
