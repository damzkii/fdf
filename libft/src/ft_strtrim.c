/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:37:57 by ahermawa          #+#    #+#             */
/*   Updated: 2022/04/13 16:53:52 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_whitespaces(char const s)
{
	while (s == ' ' || s == '\n' || s == '\t')
	{
		return (1);
	}
	return (0);
}

int	ft_backcheck(char const *s)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while (ft_whitespaces(s[i]))
	{
		i--;
	}
	if (i == 0)
	{
		i = 1;
	}
	return (i);
}

int	ft_lensize(int b, int f)
{
	int	len;

	len = b - f + 1;
	if (len < 0)
	{
		len = 0;
	}
	return (len);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	int		front;
	int		back;
	char	*str;

	i = 0;
	front = 0;
	if (!s)
		return (NULL);
	back = ft_backcheck(s);
	while (ft_whitespaces(s[front]))
		front++;
	len = ft_lensize(back, front);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[front + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
