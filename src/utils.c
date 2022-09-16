/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:39:01 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/16 19:20:06 by ahermawa         ###   ########.fr       */
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


 void    init(t_data *data)
 {
     data->gap = 30;
     data->offset = 50;
 //    data->elev = 2;
     data->clr.color = 0xFFFFFF;
 //    data->trigger = 0;
 //    data->rotate = 0.1;
     data->dir = 0;
 //    data->flows = 0;
 //    data->disco = 0;
}