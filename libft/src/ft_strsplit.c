/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:39:18 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/25 15:09:56 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *str, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
		{
			words++;
		}
		i++;
	}
	return (words);
}

static char	**ft_freshsplit(char **fresh, char const *str, char delim, int word)
{
	int	start;
	int	hold;
	int	i;

	start = 0;
	hold = 0;
	i = 0;
	while (hold < word)
	{
		while (str[i] && str[i] == delim)
			i++;
		start = i;
		while (str[i] && str[i] != delim)
			i++;
		fresh[hold] = ft_strsub(str, start, i - start);
		if (!fresh[hold])
			return (ft_free_arr((void **)fresh, word));
		hold++;
	}
	return (fresh);
}

char	**ft_strsplit(char const *s, char c)
{
	int		count;
	char	**fresh;

	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	fresh = (char **)malloc(sizeof(char *) * count + 1);
	if (!fresh)
		return (NULL);
	fresh = ft_freshsplit(fresh, s, c, count);
	if (!fresh)
		return (NULL);
	fresh[count] = 0;
	return (fresh);
}
