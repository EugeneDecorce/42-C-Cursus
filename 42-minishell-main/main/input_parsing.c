/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   input_parsing.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: user <user@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/15 01:49:23 by user			  #+#	#+#			 */
/*   Updated: 2024/07/15 01:49:39 by user			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

int handle_quotes(t_utils *data, char *line)
{
	if (open_quote(data, line))
	{
		free(line);
		return 0;
	}
	return 1;
}

int handle_fetchenv(t_utils *data, char **line) {
	if (!replace_env(line, data) || !create_list_token(&data->token, *line)) {
		free(*line);
		free_data(data, "malloc error\n", 1);
	}
	return 1;
}

int handle_pipes(t_utils *data) {
	if (data->token && data->token->prev->type == 5) {
		write(2, "Error: Unclosed pipe\n", 21);
		data->exit_code = 2;
		free_token(&data->token);
		return 0;
	}
	return 1;
}

int handle_command_list_creation(t_utils *data) {
	if (!data->token || !create_list_cmd(data)) {
		free_token(&data->token);
		free_cmd(&data->cmd);
		return 0;
	}
	return 1;
}

int input_parsing(t_utils *data, char *line) {
	if (!handle_quotes(data, line)) return 0;
	if (!handle_fetchenv(data, &line)) return 0;
	free(line);
	if (!handle_pipes(data)) return 0;
	if (!handle_command_list_creation(data)) return 0;
	return scan_pipes_errors(data);
}
