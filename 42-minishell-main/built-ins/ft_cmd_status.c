#include "../main/minishell.h"

void	ft_cmd_status(int status)
{
	char	*nb;

	nb = ft_itoa(status);
	if (nb == NULL)
	{
		setenv("?", "0", 1);
		return ;
	}
	setenv("?", nb, 1);
	free(nb);
}