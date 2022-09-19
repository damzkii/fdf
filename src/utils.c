/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:39:01 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/19 19:28:23 by ahermawa         ###   ########.fr       */
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

int     rgb_color(double r, double g, double b)
{
    int     color;

    color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}


 void    init(t_data *data)
 {
     data->gap = 30;
     data->offset = 50;
     data->elev = 2;
     data->clr.base = rgb_color(1, 1, 1);
     data->clr.vertical = rgb_color(1, 0.81, 0);
     data->clr.elevated = rgb_color(1, 0.2531, 1);
     data->trigger = 0;
 //    data->rotate = 0.1;
    // data->dir = 0;
 //    data->flows = 0;
 //    data->disco = 0;
}