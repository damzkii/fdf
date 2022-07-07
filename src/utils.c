/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:39:01 by ahermawa          #+#    #+#             */
/*   Updated: 2022/07/07 13:54:18 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    err_msg(int error, char *message)
{
    if (error == 0)
    {
        ft_putendl(message);
        exit(1);
    }
    if (error == 1)
    {
        ft_putendl(message);
        exit (1);
    }
}