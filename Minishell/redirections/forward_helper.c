/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:08:48 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/08 20:10:17 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	forward_helper(char **output, char *input, char **file1, char **file2)
{
	*output = ft_forward_output(input);
	if (*output == NULL)
		return (1);
	*file1 = ft_forward_file(input, ">");
	if (*file1 == NULL)
		return (1);
	*file2 = remove_quotes(*file1);
	free(*file1);
	if (*file2 == NULL)
		return (free(*output), 1);
	if (ft_strlen(*file2) == 0)
	{
		printf("Bash: : No such file or directory\n");
		ft_cmd_status(1);
		return (free(*output), free(*file2), 1);
	}
	return (0);
}
