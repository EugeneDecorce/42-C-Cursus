/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   exec_commands.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: edecorce <edecorce@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/10 18:46:47 by edecorce		  #+#	#+#			 */
/*   Updated: 2024/07/10 22:37:49 by edecorce		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../main/minishell.h"

void	exit_child_process(pid_t pid)
{
	int	status; 

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		ft_cmd_status(WEXITSTATUS(status));
}

void	exec_command(t_util *var)
{
	parse_user_input(var);
	if (var->args[0] == NULL)
		return ;
	exec_pipes(var);
}
