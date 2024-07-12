// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   exec_pipes_commands.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/07/11 09:35:17 by edecorce          #+#    #+#             */
// /*   Updated: 2024/07/11 17:13:29 by user             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../main/minishell.h"

// char **get_pipe_packet(t_util *var, int *cmd_end_index)
// {
//     char **packet;
//     int len = *cmd_end_index;
//     int packet_size;

//     // Find the end of the current command or the end of the arguments array
//     while (var->args[len] != NULL && strcmp(var->args[len], "|") != 0)
//         len++;

//     // Calculate the size of the packet
//     packet_size = len - *cmd_end_index + 1;
//     packet = (char **)malloc(packet_size * sizeof(char *));
//     if (packet == NULL)
//         return NULL;

//     // Copy the arguments for the current command into the packet
//     for (int i = 0; i < packet_size - 1; i++)
//     {
//         packet[i] = strdup(var->args[*cmd_end_index + i]);
//         if (packet[i] == NULL)
//         {
//             for (int j = 0; j < i; j++)
//                 free(packet[j]);
//             free(packet);
//             return NULL;
//         }
//     }
//     packet[packet_size - 1] = NULL;

//     // Update cmd_end_index to point to the next command
//     if (var->args[len] == NULL)
//         *cmd_end_index = len;
//     else
//         *cmd_end_index = len + 1;

//     return packet;
// }


// void execute_pipe_wait()
// {
//     int status;
//     while (wait(&status) > 0)
//     {
//         if (!WIFEXITED(status))
//             printf("Child terminated abnormally\n");
//         else
//             ft_cmd_status(WEXITSTATUS(status));
//     }
// }

// void execute_pipe(t_util *var)
// {
//     int in_fd = STDIN_FILENO;
//     pid_t pid;
//     int cmd_end_index = 0;
//     char **packet;

//     while (var->args[cmd_end_index])
//     {
//         packet = get_pipe_packet(var, &cmd_end_index);
//         if (packet == NULL)
//         {
//             perror("get_pipe_packet");
//             exit(EXIT_FAILURE);
//         }

//         if (pipe(var->pipefd) == -1)
//         {
//             perror("pipe");
//             exit(EXIT_FAILURE);
//         }

//         pid = fork();
//         if (pid == -1)
//         {
//             perror("fork");
//             exit(EXIT_FAILURE);
//         }
//         else if (pid == 0)  // Child process
//         {
//             // Set up input redirection
//             if (in_fd != STDIN_FILENO)
//             {
//                 dup2(in_fd, STDIN_FILENO);
//                 close(in_fd);
//             }

//             // Set up output redirection to next command (if not last command)
//             if (var->args[cmd_end_index] != NULL)
//             {
//                 dup2(var->pipefd[1], STDOUT_FILENO);
//                 close(var->pipefd[0]);
//                 close(var->pipefd[1]);
//             }

//             // Execute the command
//             handle_redirections(var);
//             ft_execvp(packet[0], packet);
//             printf("%s: command not found\n", packet[0]);
//             free(var->input);
//             ft_freemap(var->args, var->size);
//             ft_cmd_status(127);
//             exit(127);
//         }
//         else  // Parent process
//         {
//             close(var->pipefd[1]);  // Close write end of the pipe

//             if (in_fd != STDIN_FILENO)
//                 close(in_fd);  // Close previous command's input

//             in_fd = var->pipefd[0];  // Move to the next command's input

//             // Free packet memory
//             for (int i = 0; packet[i] != NULL; i++)
//                 free(packet[i]);
//             free(packet);
//         }
//     }

//     // Close the last command's input pipe
//     if (in_fd != STDIN_FILENO)
//         close(in_fd);

//     // Wait for all child processes to finish
//     execute_pipe_wait();
// }


// void	exec_pipes(t_util *var)
// {
// 	pid_t	pid;
	
// 	if (is_pipe(var->input))
// 	{
// 		execute_pipe(var);
// 	}
// 	else
// 	{
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			handle_redirections(var);
// 			ft_execvp(var->args[0], var->args);
//             printf("%s: command not found\n", var->args[0]);
//             free(var->input); 
//             ft_freemap(var->args, var->size);
//             exit(127);
// 		}
// 		else if (pid < 0)
// 			perror("fork");
// 		else
// 			exit_child_process(pid);
// 	}
// }

// 	// for (int i = 0; var->args[i]; i++)
// 	// 	printf("[%s]\n", var->args[i]);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:35:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 17:44:35 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	execute_pipe_wait(void)
{
	while (wait(NULL) > 0)
		;
}

void	pipe_commands_management(t_util *var, char ***cmd_end,
	pid_t *pid)
{
	int	i;

	i = 0;
	while ((var->args)[i] != NULL && ft_strcmp((var->args)[i], "|") != 0)
		i++;
	*cmd_end = &(var->args)[i];
	if (*(*cmd_end) != NULL)
	{
		*(*cmd_end) = NULL;
		(*cmd_end)++;
	}
	pipe(var->pipefd);
	if (*(*cmd_end) != NULL && pipe(var->pipefd) == -1)
	{
		perror("pipe");
		ft_cmd_status(127);
		exit(EXIT_FAILURE);
	}
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		ft_cmd_status(127);
		exit(EXIT_FAILURE);
	}
}

void	pipe_null_pid_management(int in_fd, t_util *var,
	char **cmd_start, char **cmd_end)
{
	if (in_fd != STDIN_FILENO)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (*(cmd_end) != NULL)
	{
		dup2(var->pipefd[1], STDOUT_FILENO);
		close(var->pipefd[0]);
		close(var->pipefd[1]);
	}
    if (!handle_redirections(var))
    {
	    ft_execvp(cmd_start[0], cmd_start);
    	printf("%s: command not found\n", cmd_start[0]);
    }
	ft_freemap(var->args, var->size);
    free(var->input);
    exit(127);
}

void	execute_pipe(t_util *var)
{
	int		in_fd;
	pid_t	pid;
	char	**cmd_start;
	char	**cmd_end;

	in_fd = STDIN_FILENO;
	cmd_start = var->args; 
	while (*var->args)
	{
		pipe_commands_management(var, &cmd_end, &pid);
		if (pid == 0)
			pipe_null_pid_management(in_fd, var, cmd_start, cmd_end);
		else
		{
			if (var->pipefd[1] != -1)
				close(var->pipefd[1]);
			if (in_fd != STDIN_FILENO)
				close(in_fd);
			in_fd = var->pipefd[0];
			cmd_start = cmd_end;
			var->args = cmd_end;
		}
	}
	execute_pipe_wait();
	//ft_freemap(var->args, var->size);
}


void	exec_pipes(t_util *var)
{
	pid_t	pid;
	
	if (is_pipe(var->input))
	{
		execute_pipe(var);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (!handle_redirections(var))
            {
                ft_execvp(var->args[0], var->args);
                printf("%s: command not found\n", var->args[0]);
            }
	        ft_freemap(var->args, var->size);
            free(var->input);
			exit(127);
		}
		else if (pid < 0)
			perror("fork");
		else
        {
			exit_child_process(pid);
	        //ft_freemap(var->args, var->size);
        }
	}
}