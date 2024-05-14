/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:04:53 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/23 12:09:34 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_args_count(int argc)
{
	if (argc == 1)
	{
		ft_putstr("Error\nThe map is missing!\n");
		exit(1);
	}
	if (argc > 2)
	{
		ft_putstr("Error\nToo many arguments entered, only one expected.\n");
		exit(1);
	}
}
