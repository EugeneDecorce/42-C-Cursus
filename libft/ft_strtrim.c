/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:09:30 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/15 18:39:48 by edecorce         ###   ########.fr       */
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

int	str_reached_end(char const *s1, int i, char const *set)
{
	while (s1[i])
	{
		if (!is_in_set(s1[i], set))
			return (0);
		i++;
	}
	return (1);
}

int	get_total_len(char const *s1, char const *set)
{
	int	str_located;
	int	len;
	int	i;

	len = 0;
	i = 0;
	str_located = 0;
	while (s1[i])
	{
		if (!is_in_set(s1[i], set))
			str_located = 1;
		if (str_located && !str_reached_end(s1, i, set))
			len++;
		i++;
	}
	return (len);
}

void	helper2(char c, char const *set, int *str_located)
{
	if (!is_in_set(c, set))
		*str_located = 1;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trimmed;
	int		str_located;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	str_trimmed = (char *) malloc((get_total_len(s1, set) + 1) * sizeof(char));
	if (str_trimmed == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str_located = 0;
	while (s1[i])
	{
		helper2(s1[i], set, &str_located);
		if (str_located && !str_reached_end(s1, i, set))
		{
			str_trimmed[j] = s1[i];
			j++;
		}
		i++;
	}
	str_trimmed[j] = '\0';
	return (str_trimmed);
}

// #include <stdio.h>

// int main()
// {
// 	char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t 
//  Please\n Trim me !\n   \n \n \t\t\n  ";
// 	char *ret = ft_strtrim(s1, " \n\t");
// 	printf("%s\n", ret);
// 	return 0;
// }