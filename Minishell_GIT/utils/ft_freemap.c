/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:58:16 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/12 01:00:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void ft_freemap(char **args)
{
    int i;

    if (args == NULL)
        return;
    i = 0;
    while (args[i])
    {
        free(args[i]);
        args[i] = NULL;
            i++;
    }
    if (args)
    {
        free(args);
        args = NULL;
    }        
}

