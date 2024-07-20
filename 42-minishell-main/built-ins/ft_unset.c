/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_unset.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: user <user@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/04/25 16:06:58 by reldnah		   #+#	#+#			 */
/*   Updated: 2024/07/15 01:25:53 by user			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../main/minishell.h"

int	does_variable_exist(char *str, t_list *env);
int	is_valid_identifier(char *str);

void	check_env(t_list *temp, t_list **env)
{
	if (temp == (*env))
		(*env) = temp->next;
	if (temp->next == temp)
		(*env) = NULL;
}

t_list*	find_env_node(t_list *env, int pos)
{
	t_list	*temp;
	int		i;

	temp = env;
	i = 0;
	while (i < pos)
	{
		temp = temp->next;
		i++;
	}
	return temp;
}

int	unset(char *str, t_list **env)
{
	t_list *temp;
	int		pos;

	pos = does_variable_exist(str, *env);
	if (!str || !(*str))
		return (0);
	if (!is_valid_identifier(str))
	{
		printf("unset: invalid identifier\n");
		return (1);
	}
	pos = does_variable_exist(str, *env);
	if (pos == -1)
		return (0);
	temp = find_env_node(*env, pos);
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp->str);
	check_env(temp, env);
	free(temp);
	return (0);
}

int	ft_unset(char **str, t_list **env)
{
	int	exit_code;
	int	i;

	exit_code = 0;
	i = 0;
	while (str[i])
	{
		if (unset(str[i], env))
			exit_code = 1;
		i++;
	}
	return (exit_code);
}
