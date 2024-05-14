/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:32:52 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/11 00:23:03 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned int		strlen;
	size_t				i;

	if (!s)
		return (0);
	strlen = start;
	while (s[strlen])
		strlen++;
	if (start > strlen)
		len = 0;
	else if (strlen < len)
		len = strlen;
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