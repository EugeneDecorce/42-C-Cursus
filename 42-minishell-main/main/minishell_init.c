/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   minishell_init.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: user <user@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/15 01:34:05 by user			  #+#	#+#			 */
/*   Updated: 2024/07/15 01:34:13 by user			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

void	env_constructor(t_utils *data, char **env);

void	initialize_data(t_utils *data)
{
	data->env = NULL;
	data->token = NULL;
	data->cmd = NULL;
	data->exit_code = 0;
	data->pip[0] = -1;
	data->pip[1] = -1;
	g_signal_pid = 0;
}

void	data_initialisation(t_utils *data, char **env, int argc, char **argv)
{
	(void) argc;
	(void) argv;

	if (!getenv("PATH"))
		exit(0);
	initialize_data(data);
	env_constructor(data, env);
	complete_signals();
}
