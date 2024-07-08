/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_with_pipes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:29:02 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/08 05:04:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int is_builtin(const char *command) {
    return (strcmp(command, "echo") == 0 || 
            strcmp(command, "pwd") == 0 || 
            strcmp(command, "cd") == 0);
}
void execute_builtin(char **args) {
	for (int i = 0; args[i]; i++)
		printf("[%s]\n", args[i]);
	printf("LLLL");
    if (strcmp(args[0], "echo") == 0) {
        ft_echo(args[1]);
    } else if (strcmp(args[0], "pwd") == 0) {
        ft_pwd();
    } else if (strcmp(args[0], "cd") == 0) {
        ft_cd(args[1]);
    }
    // Add other built-ins as needed
}




void	execute_command(char **args)
{
	char	*command_path;

	command_path = get_command_path(args[0]);
	if (command_path == NULL)
	{
		printf("minishell: %s: command not found\n", args[0]);
		ft_cmd_status(127);
		free(args);
		exit(127);
	}
	if (execv(command_path, args) == -1)
	{
		perror("execv error in minishell");
		exit(EXIT_FAILURE);
	}
}

void	setup_child_pipes(int i, int num_commands, int in_fd, int pipe_fds[2])
{
	if (in_fd != STDIN_FILENO)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (i < num_commands - 1)
	{
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipe_fds[1]);
	}
}

int	split_commands(int *in_fd, char *input, char *commands[])
{
	int		num_commands;
	char	*command;

	*in_fd = STDIN_FILENO;
	num_commands = 0;
	command = strtok(input, "|");
	while (command != NULL)
	{
		commands[num_commands++] = command;
		command = strtok(NULL, "|");
	}
	commands[num_commands] = NULL;
	return (num_commands);
}

int run_builtin_with_pipe(char **args, int out_fd) {
    int saved_stdout = dup(STDOUT_FILENO);
    dup2(out_fd, STDOUT_FILENO);
    close(out_fd);
    
    execute_builtin(args);
    
    fflush(stdout);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    return 0;
}

int helper(int i, char ***args, int num_commands, int *in_fd) {
    int pipe_fds[2];
    pid_t pid;

    // Create a pipe if this is not the last command
    if (i < num_commands - 1) {
        if (create_pipe(pipe_fds) != 0) {
            return 1;
        }
    }

    // Check if the command is a built-in
    if (is_builtin((*args)[0])) {
        if (i < num_commands - 1) {
            // Built-in and not the last command: pipe the output
            run_builtin_with_pipe(*args, pipe_fds[1]);
            close(pipe_fds[1]);
            close(pipe_fds[0]);
        } else {
            // Built-in and the last command: execute directly
            if (*in_fd != STDIN_FILENO) {
                dup2(*in_fd, STDIN_FILENO);
                close(*in_fd);
            }
            execute_builtin(*args);
        }
    } else {
        // External command
        pid = fork();
        if (pid == 0) {
            // Child process
            setup_child_pipes(i, num_commands, *in_fd, pipe_fds);
            execute_command(*args);
        } else if (pid < 0) {
            // Fork failed
            return 1;
        }
    }

    // Parent process: update the input fd for the next command
    *in_fd = update_input_fd(*in_fd, i, num_commands, pipe_fds);
    return 0;
}


int	exec_command_with_pipes(char *input, int i)
{
	char	**args;
	char	*commands[MAX_ARGS];
	int		num_commands;
	int		in_fd;

	num_commands = split_commands(&in_fd, input, commands);
	while (i < num_commands)
	{
		args = parse_user_input(commands[i]);
		if (helper(i, &args, num_commands, &in_fd))
			return (1);
		free(args);
		i++;
	}
	return (wait_for_all_commands(num_commands));
}
