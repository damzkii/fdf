/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:14:04 by ahermawa          #+#    #+#             */
/*   Updated: 2022/04/13 16:51:31 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	int		j;
	int		len;

	j = 0;
	i = ft_strlen(dest);
	len = ft_strlen(src);
	while (len > 0)
	{
		dest[i] = src[j];
		i++;
		j++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
