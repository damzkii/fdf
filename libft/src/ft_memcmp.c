/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:02:54 by ahermawa          #+#    #+#             */
/*   Updated: 2022/04/13 16:50:09 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*newstr1;
	const unsigned char	*newstr2;

	i = 0;
	newstr1 = str1;
	newstr2 = str2;
	while (i < n)
	{
		if (newstr1[i] != newstr2[i])
		{
			return (newstr1[i] - newstr2[i]);
		}
		i++;
	}
	return (0);
}
