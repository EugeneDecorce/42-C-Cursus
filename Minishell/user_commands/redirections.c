/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:54:52 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/10 19:02:43 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	handle_simple_forward(int *fd, char ***args, int i)
{
	*fd = open((*args)[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(*fd, STDOUT_FILENO);
	close(*fd);
	(*args)[i] = NULL;
}

void	handle_double_forward(int *fd, char ***args, int i)
{
	*fd = open((*args)[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(*fd, STDOUT_FILENO);
	close(*fd);
	(*args)[i] = NULL;
}

void	handle_simple_backward(int *fd, char ***args, int i)
{
	*fd = open((*args)[i + 1], O_RDONLY);
	if (*fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(*fd, STDIN_FILENO);
	close(*fd);
	(*args)[i] = NULL;
}

void	navigate_redirections(char ***args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*args)[i] != NULL)
	{
		if ((*args)[i] != NULL)
		{
			if (ft_strcmp((*args)[i], ">") == 0
				|| ft_strcmp((*args)[i], ">>") == 0
					|| ft_strcmp((*args)[i], "<") == 0
						|| ft_strcmp((*args)[i], "<<") == 0)
			{
				i += 2;
				continue ;
			}
		}
		(*args)[j++] = (*args)[i++];
	}
	(*args)[j] = NULL;
}

void	handle_redirections(char **args)
{
	int	i;
	int	fd;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strcmp(args[i], ">") == 0)
			handle_simple_forward(&fd, &args, i);
		else if (ft_strcmp(args[i], ">>") == 0)
			handle_double_forward(&fd, &args, i);
		else if (strcmp(args[i], "<") == 0)
			handle_double_forward(&fd, &args, i);
		else if (ft_strcmp(args[i], "<<") == 0)
		{
			handle_heredoc(args[i + 1]);
			args[i] = NULL;
			args[i + 1] = NULL;
		}
		i++;
	}
	navigate_redirections(&args);
}
