/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:58:16 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/11 20:36:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void ft_freemap(char **args, int size)
{
    if (args == NULL)
        return;

    for (int i = 0; i < size; i++)
    {
        if (args[i] != NULL)
        {
            free(args[i]);
            args[i] = NULL; // Optional: Set pointer to NULL after freeing
        }
    }

    free(args);
}

