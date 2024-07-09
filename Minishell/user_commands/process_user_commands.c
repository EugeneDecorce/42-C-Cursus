/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_user_commands.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:30:12 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/08 22:40:10 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	handle_heredoc_redirection(char **args, int index)
{
	FILE	*temp_file;
	int		in_fd;
	char	*delimiter;
	char	line[1024];

	if (args[index + 1] != NULL)
	{
		if (hdoc_helper(&delimiter, &temp_file, args, index) == -1)
			return (-1);
		while (fgets(line, sizeof(line), stdin))
		{
			if (ft_strncmp(line, delimiter, strlen(delimiter)) == 0
				&& line[strlen(delimiter)] == '\n')
				break ;
			fputs(line, temp_file);
			printf("> ");
		}
		hdoc_helper2(temp_file, &args, index, &in_fd);
		return (in_fd);
	}
	else
	{
		printf("minishell: syntax error near unexpected token newline'\n");
		return (-1);
	}
}

int	handle_file_redirection(char **args, int index)
{
	int	in_fd;

	if (args[index + 1] != NULL)
	{
		in_fd = open(args[index + 1], O_RDONLY);
		if (in_fd == -1)
		{
			perror("minishell: error opening file for input redirection");
			return (-1);
		}
		args[index] = NULL;
		args[index + 1] = NULL;
		return (in_fd);
	}
	else
	{
		printf("minishell: syntax error near unexpected token newline'\n");
		return (-1);
	}
}

int	process_input_redirection(char **args, char *input)
{
	int	in_fd;
	int	i;

	in_fd = -1;
	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strcmp(args[i], "<") == 0
			&& !is_in_quote(input, ft_strstr(input, "<") - input))
		{
			in_fd = handle_file_redirection(args, i);
			break ;
		}
		else if (ft_strcmp(args[i], "<<") == 0
			&& !is_in_quote(input, ft_strstr(input, "<<") - input))
		{
			in_fd = handle_heredoc_redirection(args, i);
			break ;
		}
		i++;
	}
	return (in_fd);
}

int	handle_output_redirection(char **args,
	int *out_fds, int *num_out_fds, int append)
{
	int	flags;
	int	i;
	int	fd;

	flags = O_WRONLY | O_CREAT;
	if (append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	i = 0;
	while (args[i] != NULL)
	{
		if ((ft_strcmp(args[i], ">") == 0 || ft_strcmp(args[i], ">>") == 0)
			&& !is_in_quote(args[i], i))
		{
			fd = open(args[i + 1], flags, 0644);
			if (fd == -1)
				return (-1);
			out_fds[*num_out_fds] = fd;
			(*num_out_fds)++;
			args[i] = NULL;
			args[i + 1] = NULL;
		}
	}
	return (0);
}

int	process_output_redirection(char **args, int *out_fds, int *num_out_fds)
{
	int	i;
	int	flags;
	int	fd;

	i = 0;
	while (args[i] != NULL)
	{
		if ((ft_strcmp(args[i], ">") == 0 || ft_strcmp(args[i], ">>") == 0)
			&& !is_in_quote(args[i], i))
		{
			flags = redirection_flags(args[i]);
			if (args[i + 1] == NULL)
				return (-1);
			fd = open(args[i + 1], flags, 0644);
			if (fd == -1)
				return (-1);
			out_fds[*num_out_fds] = fd;
			(*num_out_fds)++;
			args[i] = NULL;
			args[i + 1] = NULL;
		}
		i++;
	}
	return (0);
}
