/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:44:20 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/20 08:16:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_signal_pid;

int input_parsing(t_utils *data, char *line);

void	check_env_status(t_utils *data)
{
	char	*status;

	status = getenv("?");
	g_signal_pid = 0;

	if (ft_strncmp(status, "131", 3) || ft_strncmp(status, "130", 3))
	{
		printf("PP");
		export_variable("?=131", &(data->env));
		setenv("?", "0", 1);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_utils	data;
	char	*line;

	data_initialisation(&data, env, argc, argv);
	if (data.env == NULL)
		free_data(&data, "malloc error\n", 1);
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
			free_data(&data, "exit\n", 130);
		if (ft_isempty(line))
			continue ;
		add_history(line);
		if (!input_parsing(&data, line))
			continue ;
		if (!exec(&data))
			free_data(&data, "pipe error\n", 1);
		free_cmd(&data.cmd);
		free_token(&data.token);
		g_signal_pid = 0;
	}
	rl_clear_history();
	free_data(&data, NULL, -1);
	return (0);
}
