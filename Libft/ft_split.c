/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:19:55 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/11 00:27:53 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	ft_word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**allocate_and_fill(char const *s, char c, char **tab, int word_count)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i] && j < word_count)
	{
		k = 0;
		while (s[i] == c)
			i++;
		tab[j] = malloc(sizeof(char) * (ft_word_len(s, c, i) + 1));
		if (!tab[j])
			return (0);
		while (s[i] && s[i] != c)
			tab[j][k++] = s[i++];
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word_count;

	if (!s)
		return (0);
	word_count = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (0);
	return (allocate_and_fill(s, c, tab, word_count));
}
/*
#include <stdio.h>

int main()
{
	char *s = "HelloWorld";
	char c = ' ';
	char **tab = ft_split(s, c);
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return 0;
}*/