/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:32:52 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/15 18:39:48 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

unsigned int	ft_strlen4(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	helper(char const *s, unsigned int start,
				unsigned int *strlen, size_t *len)
{
	*strlen = start;
	while (s[*strlen])
		(*strlen)++;
	if (start > *strlen)
		*len = 0;
	else if (*strlen < *len)
		*len = *strlen;
}

char	*get_empty(void)
{
	char	*empty_str;

	empty_str = (char *) malloc(sizeof(char));
	if (empty_str == NULL)
		return (NULL);
	empty_str[0] = '\0';
	return (empty_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned int		strlen;
	size_t				i;

	if (!s)
		return (0);
	if (start >= ft_strlen4(s))
		return (get_empty());
	helper(s, start, &strlen, &len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

int main()
{
    char *s = "Hello, World!";
    unsigned int start = 77;
    size_t len = 5;
    char *substr = ft_substr(s, start, len);

    if (substr != NULL)
    {
        printf("Substring: %s\n", substr);
        free(substr);  // Don't forget to free the memory!
    }
    else
    {
        printf("Failed to allocate memory for substring.\n");
    }

    return 0;
}*/