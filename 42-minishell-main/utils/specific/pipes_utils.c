#include "../../main/minishell.h"

int	scan_pipes_errors(t_utils *data)
{
	if (data->token->type == 5)
	{
		write(2, "syntax error near unexpected token '|'\n", 39);
		free_token(&data->token);
		free_cmd(&data->cmd);
		return (0);
	}
	return (1);
}