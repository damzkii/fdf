/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:52:34 by ahermawa          #+#    #+#             */
/*   Updated: 2022/04/13 16:52:37 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	ret;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (n > dstlen)
		ret = dstlen + srclen;
	else
		ret = n + srclen;
	if (dstlen < n - 1 && n > 0)
	{
		while (src[i] && dstlen < n - 1)
		{
			dst[dstlen] = src[i];
			i++;
			dstlen++;
		}
		dst[dstlen] = '\0';
	}
	return (ret);
}
