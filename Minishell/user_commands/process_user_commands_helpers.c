/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_user_commands_helpers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:58:39 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/09 22:42:36 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"


int hdoc_helper(char **delimiter, int *temp_fd, char **args, int index) {
    *delimiter = args[index + 1];
    *temp_fd = open("/tmp/minishell_heredoc_tempfile", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (*temp_fd == -1) {
        perror("minishell: here document error");
        return -1;
    }
    printf("> ");
    return 0;
}

void hdoc_helper2(int temp_fd, char ***args, int index, int *in_fd) {
    // Close the temporary file descriptor to flush any pending writes
    close(temp_fd);

    // Reopen the file for reading
    temp_fd = open("/tmp/minishell_heredoc_tempfile", O_RDONLY);
    if (temp_fd == -1) {
        perror("minishell: here document error");
        return;
    }

    // Set the input file descriptor to the opened temporary file
    *in_fd = temp_fd;

    // Mark the corresponding elements in args as NULL
    (*args)[index] = NULL;
    (*args)[index + 1] = NULL;
}

int redirection_flags(char *arg) {
    if (strcmp(arg, ">>") == 0)
        return O_WRONLY | O_CREAT | O_APPEND;
    else
        return O_WRONLY | O_CREAT | O_TRUNC;
}