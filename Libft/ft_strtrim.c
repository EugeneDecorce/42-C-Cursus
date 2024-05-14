/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:09:30 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/11 00:22:40 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_total_len(char const *s1, char const *set)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s1[i])
	{
		if (!is_in_set(s1[i], set))
			len++;
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trimmed;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	str_trimmed = (char *) malloc((get_total_len(s1, set) + 1) * sizeof(char));
	if (str_trimmed == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!is_in_set(s1[i], set))
		{
			str_trimmed[j] = s1[i];
			j++;
		}
		i++;
	}
	str_trimmed[j] = '\0';
	return (str_trimmed);
}
/*
#include <stdio.h>

int main()
{
	char *s1 = "Hello World";
	char *set = "8";
	printf("%s\n", ft_strtrim(s1, set));
	return 0;
}*/