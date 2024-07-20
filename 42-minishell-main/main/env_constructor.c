/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   env_constructor.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: user <user@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/15 01:32:06 by user			  #+#	#+#			 */
/*   Updated: 2024/07/15 01:32:06 by user			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

void	handle_empty_env(t_utils *data)
{
	char	path[PATH_MAX];
	char	*temp;
	
	temp = ft_strdup("OLDPWD");
	if (!temp || !append(&(data->env), temp) || getcwd(path, PATH_MAX) == NULL)
	{
		free_data(data, "malloc error\n", 1);
	}
	temp = ft_strjoin("PWD=", path);
	if (!temp || !append(&(data->env), temp))
	{
		free_data(data, "malloc error\n", 1);
	}
}

void	add_env_variable(t_list **list, char *env_var)
{
	char	*temp;
	
	temp = ft_strdup(env_var);
	if (!temp || !append(list, temp))
	{
		free_list(list);
	}
}

void	populate_env_list(t_utils *data, char **env)
{
	t_list	*list;
	int		i;
	
	list = NULL;
	i = 0;
	while (env[i])
	{
		add_env_variable(&list, env[i]);
		i++;
	}
	data->env = list;
}

void	env_constructor(t_utils *data, char **env)
{
	if (!(*env))
	{
		handle_empty_env(data);
		return;
	}
	populate_env_list(data, env);
}
