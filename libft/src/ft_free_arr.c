/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:05:20 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/25 15:06:30 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_arr(void **array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_free(array[i], ft_strlen(array[i]));
		i++;
	}
	free(array);
	array = NULL;
	return (NULL);
}
