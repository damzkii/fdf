/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:35:21 by ahermawa          #+#    #+#             */
/*   Updated: 2022/04/13 16:50:21 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	d = dst;
	s = src;
	i = 1;
	if (dst > src)
	{
		while (len >= i)
		{
			d[len - i] = s[len - i];
			i++;
		}
		return (d);
	}
	return (ft_memcpy(d, s, len));
}
