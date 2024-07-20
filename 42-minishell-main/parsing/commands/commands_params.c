/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:09:22 by reldnah           #+#    #+#             */
/*   Updated: 2024/07/15 03:21:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main/minishell.h"

int should_count_token(t_utils *data, t_token *temp)
{
    return (temp->type == 6 || (temp->type == 7 && temp->prev != data->token->prev && temp->prev->type > 5));
}

int count_args(t_utils *data, t_token *token)
{
    int count = 0;
    t_token *temp = token;

    if (should_count_token(data, temp))
        count++;
    temp = temp->next;

    while (temp != data->token && temp->type != 5)
    {
        if (should_count_token(data, temp))
            count++;
        temp = temp->next;
    }
    return count;
}

int add_to_cmd_param(char **cmd_param, int *i, char *str)
{
    cmd_param[*i] = ft_strdup(str);
    if (!cmd_param[*i])
        return 0;
    (*i)++;
    return 1;
}

void *free_cmd_param(char **cmd, int i)
{
    while (--i >= 0)
        free(cmd[i]);
    free(cmd);
    return NULL;
}

int should_add_to_cmd_param(t_utils *data, t_token *temp)
{
    return (temp->type != 5 && should_count_token(data, temp));
}

char **get_param(t_utils *data, t_token *token)
{
    char **cmd_param;
    int i = 0;
    t_token *temp = token;

    cmd_param = malloc(sizeof(char *) * (count_args(data, token) + 1));
    if (cmd_param == NULL)
        return NULL;

    if (should_add_to_cmd_param(data, temp) && !add_to_cmd_param(cmd_param, &i, temp->str))
        return free_cmd_param(cmd_param, i);

    temp = temp->next;

    while (temp != data->token && temp->type != 5)
    {
        if (should_add_to_cmd_param(data, temp) && !add_to_cmd_param(cmd_param, &i, temp->str))
            return free_cmd_param(cmd_param, i);
        temp = temp->next;
    }

    cmd_param[i] = NULL;
    return cmd_param;
}

