/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:54:52 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 17:13:52 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	handle_simple_forward(int *fd, t_util *var, int i)
{
	*fd = open((var->args)[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd == -1)
	{
		printf("%s", var->args[i + 1]);
		ft_freemap(var->args);
		ft_freemap(var->result);
		free(var->input);
		exit(EXIT_FAILURE);
	}
	dup2(*fd, STDOUT_FILENO);
	close(*fd);
	(var->args)[i] = NULL;
}

void	handle_double_forward(int *fd, t_util *var, int i)
{
	*fd = open((var->args)[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*fd == -1)
	{
		printf("%s", var->args[i + 1]);
		ft_freemap(var->args);
		ft_freemap(var->result);
		free(var->input);
		exit(EXIT_FAILURE);
	}
	dup2(*fd, STDOUT_FILENO);
	close(*fd);
	(var->args)[i] = NULL;
}

void	handle_simple_backward(int *fd, t_util *var, int i)
{
	*fd = open((var->args)[i + 1], O_RDONLY);
	if (*fd == -1)
	{
		printf("%s", var->args[i + 1]);
		ft_freemap(var->args);
		ft_freemap(var->result);
		free(var->input);
		exit(EXIT_FAILURE);
	}
	dup2(*fd, STDIN_FILENO);
	close(*fd);
	(var->args)[i] = NULL;
}

void	navigate_redirections(t_util *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((var->args)[i] != NULL)
	{
		if ((var->args)[i] != NULL)
		{
			if (ft_strcmp((var->args)[i], ">") == 0
				|| ft_strcmp((var->args)[i], ">>") == 0
					|| ft_strcmp((var->args)[i], "<") == 0
						|| ft_strcmp((var->args)[i], "<<") == 0)
			{
				i += 2;
				continue ;
			}
		}
		(var->args)[j++] = (var->args)[i++];
	}
	(var->args)[j] = NULL;
}

void	handle_redirections(t_util *var)
{
	int	i;
	int	fd;

	i = 0;
	while (var->args[i] != NULL)
	{
		if (ft_strcmp(var->args[i], ">") == 0)
			handle_simple_forward(&fd, var, i);
		else if (ft_strcmp(var->args[i], ">>") == 0)
			handle_double_forward(&fd, var, i);
		else if (strcmp(var->args[i], "<") == 0)
			handle_simple_backward(&fd, var, i);
		else if (ft_strcmp(var->args[i], "<<") == 0)
		{
			handle_heredoc(var->args[i + 1]);
			var->args[i] = NULL;
			var->args[i + 1] = NULL;
		}
		i++;
	}
	navigate_redirections(var);
}
