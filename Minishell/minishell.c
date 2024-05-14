/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:11:53 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/30 14:38:19 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd()
{
	char	cwd[4096];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("Cannot get pwd, getcwd() returns an error");
}

void	ft_env()
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

void	ft_exit()
{
	printf("exit\n");
	exit(0);
}

int	is_echo_option(char *input, int i)
{
	int	option;
	int	j;

	option = 0;
	j = i;
	while (input[i] == '-' && input[i + 1] == 'n'
			&& (input[i + 2] == 'n' || input[i + 2] == ' '))
	{
		i += 2;
		while (input[i] == 'n')
		{
			i++;
		}
		while (input[i] == ' ')
		{
			option = 1;
			i++;
		}
	}
	if (option)
		return (i - j);
	else
		return (0);
}

void	ft_echo(char *input)
{
	int	option;
	int	i;

	i = 4;
	while (input[i] == ' ')
		i++;
	option = is_echo_option(input, i);
	i += option;
	while (input[i])
	{
		write(1, &input[i], 1);
		if (input[i] == ' ')
		{
			while (input[i] == ' ')
				i++;
		}
		else 
			i++;
	}
	if (!option)
		write(1, "\n", 1);
}

void	ft_cd(char *input)
{
	int		i;
	char	*path;

	i = 2;
	while (input[i] == ' ')
		i++;
	path = &input[i];
	if (path[0] == '\0')
		path = getenv("HOME");
	if (input[2] != ' ' && input[2] != '\0')
		printf("Bash: %s: command not found\n", input);
	else if (chdir(path) != 0)
		perror("cd");
}


extern char **environ;

void	ft_export(void)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		printf("declare -x %s\n", environ[i]);
		i++;
	}
}

void	input_manager(char *input)
{
	add_history(input);
	if (ft_strncmp(input, "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(input, "exit", 4) == 0)
		ft_exit();
	else if (ft_strncmp(input, "env", 3) == 0)
		ft_env();
	else if (ft_strncmp(input, "history -c", 10) == 0)
		printf("How to clear history ?");
	else if (ft_strncmp(input, "echo", 4) == 0)
		ft_echo(input);
	else if (ft_strncmp(input, "cd", 2) == 0)
		ft_cd(input);
	else if (ft_strncmp(input, "export", 6) == 0)
		ft_export();
	else if (input[0] != 0)
		printf("Bash: %s: command not found\n", input);
}

void	sigint_handler(int signum)
{
	(void) signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	minishell()
{
	char			*input;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_handler);
	while (1)
	{
		input = readline("minishell: ");
		if (input)
			input_manager(input);
		else
			exit(0);
		free(input);
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		printf("This program does not take any argument !");
	else
	{
		while (1)
			minishell();
	}
	return (0);
}
