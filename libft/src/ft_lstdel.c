/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:52:10 by ahermawa          #+#    #+#             */
/*   Updated: 2022/04/13 16:49:31 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*head;
	t_list	*temp;

	if (!alst || !del)
		return ;
	head = *alst;
	while (head)
	{
		(*del)(head->content, head->content_size);
		temp = head->next;
		free(head);
		head = temp;
	}
	*alst = NULL;
}
