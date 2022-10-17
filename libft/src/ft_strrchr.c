/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:37:28 by ahermawa          #+#    #+#             */
/*   Updated: 2022/04/13 16:53:27 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str) + 1;
	while (str[i])
	{
		i++;
	}
	while (len > 0)
	{
		if (str[i] == c)
		{
			return ((char *)&str[i]);
		}
		len--;
		i--;
	}
	return (NULL);
}
