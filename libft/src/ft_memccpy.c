/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:57:47 by ahermawa          #+#    #+#             */
/*   Updated: 2022/04/13 16:50:01 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		stopc;
	const unsigned char	*newsrc;
	unsigned char		*newdst;

	i = 0;
	stopc = c;
	newsrc = src;
	newdst = dst;
	while (i < n)
	{
		newdst[i] = newsrc[i];
		if (newsrc[i] == stopc)
		{
			return ((void *) &newdst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
