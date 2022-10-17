/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:30:13 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/17 13:44:36 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(void *arr, size_t len)
{
	if (!arr)
		return ;
	ft_bzero(arr, len);
	free(arr);
}
