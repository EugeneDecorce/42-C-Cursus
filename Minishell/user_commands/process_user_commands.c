/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_user_commands.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:30:12 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/09 22:42:31 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"


int handle_heredoc_redirection(char **args, int index)
{
    int temp_fd;
    int in_fd;
    char *delimiter;
    char *line = NULL;
    size_t line_len = 0;
    ssize_t read_len;

    if (args[index + 1] != NULL) {
        if (hdoc_helper(&delimiter, &temp_fd, args, index) == -1)
            return -1;

        while ((read_len = getline(&line, &line_len, stdin)) != -1) {
            if (strncmp(line, delimiter, strlen(delimiter)) == 0
                && line[strlen(delimiter)] == '\n')
                break;
            write(temp_fd, line, read_len);
            printf("> ");
        }

        free(line);
        hdoc_helper2(temp_fd, &args, index, &in_fd);
        return in_fd;
    } else {
        printf("minishell: syntax error near unexpected token 'newline'\n");
        return -1;
    }
}

int handle_file_redirection(char **args, int index) {
    int in_fd;

    if (args[index + 1] != NULL) {
        in_fd = open(args[index + 1], O_RDONLY);
        if (in_fd == -1) {
            perror("minishell: error opening file for input redirection");
            return -1;
        }
        args[index] = NULL;
        args[index + 1] = NULL;
        return in_fd;
    } else {
        printf("minishell: syntax error near unexpected token 'newline'\n");
        return -1;
    }
}

int process_input_redirection(char **args, char *input) {
    int in_fd;
    int i = 0;

    in_fd = -1;
    while (args[i] != NULL) {
        if (strcmp(args[i], "<") == 0
            && !is_in_quote(input, strstr(input, "<") - input)) {
            in_fd = handle_file_redirection(args, i);
            break;
        } else if (strcmp(args[i], "<<") == 0
            && !is_in_quote(input, strstr(input, "<<") - input)) {
            in_fd = handle_heredoc_redirection(args, i);
            break;
        }
        i++;
    }
    return in_fd;
}

int handle_output_redirection(char **args, int *out_fds, int *num_out_fds, int append) {
    int flags;
    int i = 0;
    int fd;

    flags = O_WRONLY | O_CREAT;
    if (append)
        flags |= O_APPEND;
    else
        flags |= O_TRUNC;

    while (args[i] != NULL) {
        if ((strcmp(args[i], ">") == 0 || strcmp(args[i], ">>") == 0)
            && !is_in_quote(args[i], i)) {
            fd = open(args[i + 1], flags, 0644);
            if (fd == -1)
                return -1;
            out_fds[*num_out_fds] = fd;
            (*num_out_fds)++;
            args[i] = NULL;
            args[i + 1] = NULL;
        }
        i++;
    }
    return 0;
}

int process_output_redirection(char **args, int *out_fds, int *num_out_fds) {
    int i = 0;
    int flags;
    int fd;

    while (args[i] != NULL) {
        if ((strcmp(args[i], ">") == 0 || strcmp(args[i], ">>") == 0)
            && !is_in_quote(args[i], i)) {
            flags = redirection_flags(args[i]);
            if (args[i + 1] == NULL)
                return -1;
            fd = open(args[i + 1], flags, 0644);
            if (fd == -1)
                return -1;
            out_fds[*num_out_fds] = fd;
            (*num_out_fds)++;
            args[i] = NULL;
            args[i + 1] = NULL;
        }
        i++;
    }
    return 0;
}