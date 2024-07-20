#include "../../../main/minishell.h"

int	ft_isempty(char *str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	free(str);
	return (1);
}