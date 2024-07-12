/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:54:29 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 20:11:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell

#include "../main/minishell.h"

int	handle_heredoc_breakloop(char buffer[MAX_PATH_LENGTH], int *index)
{
	if (buffer[*index] == '\n' || *index >= MAX_PATH_LENGTH - 1)
	{
		buffer[*index] = '\0';
		return (1);
	}
	(*index)++;
	return (0);
}
// int sig_num = 0;

// void handle_sigint(int sig)
// {
//     (void)sig;
// 	sig_num = sig;
// 	//write(1, '0' + sig, 1);
// 	//exit(130);
// }

// signal(SIGINT, handle_sigint);
// signal(SIGQUIT, handle_sigint);

// if (sig_num)
// 		{
// 			exit(130);
// 		}

void	handle_heredoc(char *delimiter)
{
	char	buffer[MAX_PATH_LENGTH];
	int		pipefd[2];
	int		n;
	int		index;

	pipe(pipefd);
	memset(buffer, 0, sizeof(buffer));
	while (1)
	{
		write(1, "heredoc> ", 9);
		index = 0;
		n = read(STDIN_FILENO, &buffer[index], 1);
		while (n > 0)
		{
			if (handle_heredoc_breakloop(buffer, &index))
				break ;
			n = read(STDIN_FILENO, &buffer[index], 1);
		}
		if (ft_strcmp(buffer, delimiter) == 0)
			break ;
		write(pipefd[1], buffer, ft_strlen(buffer));
		write(pipefd[1], "\n", 1);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
}
