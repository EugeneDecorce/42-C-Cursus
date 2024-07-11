/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:54:29 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/10 18:54:43 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	handle_heredoc(char *delimiter)
{
	char	buffer[MAX_PATH_LENGTH];
	int		pipefd[2];
	int		n;
	int		index;

	pipe(pipefd);
	while (1)
	{
		printf("heredoc> ");
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
