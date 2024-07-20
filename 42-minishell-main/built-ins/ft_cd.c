/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:38:32 by handler           #+#    #+#             */
/*   Updated: 2024/07/20 06:26:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	change_previous_pwd(t_utils *util);
void	change_current_pwd(t_utils *util, char *param);


int	ft_cd(t_utils *util, char **params)
{
	char	*working_directory;
	int		status;

	if (params[1] == NULL)
		working_directory = "/home/user";
	else
		working_directory = params[1];
	status = chdir(working_directory);
	if (status == -1)
	{
		printf(working_directory);
		status = 1;
	}
	else if (status == 0)
		change_current_pwd(util, working_directory);
	return (status);
}

void	fetch_pwd_env(char **prt_pwd, t_utils *util)
{
	t_list	*temp;
	int		size;

	temp = util->env;
	*prt_pwd = NULL;
	size = ft_lstsize(temp);
	while (size > 0)
	{
		if (ft_strncmp(temp->str, "PWD=", 3) == 0)
			*prt_pwd = temp->str;
		temp = temp->next;
		size--;
	}
}

void	change_previous_pwd(t_utils *util)
{
	char	*prt_pwd;

	fetch_pwd_env(&prt_pwd, util);
	if (prt_pwd == NULL)
		export_variable("OLDPWD", &util->env);
	else if (prt_pwd)
	{
		prt_pwd = ft_strjoin("OLD", prt_pwd);
		if (prt_pwd == NULL)
		{
			printf("malloc error\n");
			return ;
		}
		export_variable(prt_pwd, &util->env);
	}
	free(prt_pwd);
}

void	change_current_pwd(t_utils *util, char *param)
{
	char	working_dir[PATH_MAX];
	char	*prt_wd;

	change_previous_pwd(util);
	if (getcwd(working_dir, PATH_MAX) == NULL)
	{
		printf("%s", param);
		return ;
	}
	prt_wd = ft_strjoin("PWD=", working_dir);
	if (!prt_wd)
	{
		printf("malloc error\n");
		return ;
	}
	export_variable(prt_wd, &util->env);
	free(prt_wd);
}
