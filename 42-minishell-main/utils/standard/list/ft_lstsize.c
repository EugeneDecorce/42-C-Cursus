#include "../../../main/minishell.h"

size_t	ft_lstsize(t_list *list)
{
	t_list	*temp;
	size_t	i;

	if ((list))
	{
		temp = list;
		i = 1;
		while (temp->next != list)
		{
			++i;
			temp = temp->next;
		}
		return (i);
	}
	return (0);
}
