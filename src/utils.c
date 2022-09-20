/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:39:01 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/20 21:42:35 by ahermawa         ###   ########.fr       */
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
     data->elev = 4;
     data->clr.base = rgb_color(1, 1, 1);
     data->clr.vertical = rgb_color(1, 0.81, 0);
     data->clr.elevated = rgb_color(1, 0.2531, 1);
     data->trigger = 0;
     //data->rotate = 0.1;
     data->slide = 0;
     data->toggle = 0;
 //    data->flows = 0;
 //    data->disco = 0;
}

void    command_string(t_data *data)
{
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 30, 0xFFFFFF, "Commands:");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 60, 0xFFFFF, "Move with WASD");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 80, 0xFFFFF, "Arrow left  : Toggle two solid color 3D");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 100, 0xFFFFF, "Arrow up    : Elevates 3D");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 120, 0xFFFFF, "Arrow down  : Delevates 3D");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 140, 0xFFFFF, "Arrow right : Toggles back to 2D");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 160, 0xFFFFF, "    +       : Zoom in");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 180, 0xFFFFF, "    -       : Zoom out");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 200, 0xFFFFF, "    T       : Toggle to one solid color 3D");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 220, 0xFFFFF, "    X       : Toggle to three solid color 3D");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 240, 0xFFFFF, "    C       : Change color");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 260, 0xFFFFF, "    V       : Shaded vertical lines");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 280, 0xFFFFF, "  T or <-   : Toggles back to solid vertical lines");
    mlx_string_put(data->arg.mlx, data->arg.win, 30, 310, 0xFFFFFF, "Esc: Exit the program");
}
