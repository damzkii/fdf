/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:34:13 by ahermawa          #+#    #+#             */
/*   Updated: 2022/04/13 16:53:24 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		tmp = i;
		while ((haystack[i] == needle[j]) && haystack[i] && i < len)
		{
			i++;
			j++;
		}
		if (j == ft_strlen(needle))
			return ((char *)&haystack[i - j]);
		i = tmp;
		j = 0;
		i++;
	}
	return (NULL);
}
