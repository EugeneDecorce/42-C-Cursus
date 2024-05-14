/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:41:15 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/10 18:39:48 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include <stdio.h>

char to_upper(unsigned int i, char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}
int main(void)
{
	char str[] = "Hello, World!";
	char *result = ft_strmapi(str, to_upper);
	printf("Result: %s\n", result);
	free(result);
	return 0;
}*/