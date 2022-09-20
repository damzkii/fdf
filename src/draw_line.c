/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:49:08 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/20 21:40:29 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    pixel_color(t_data *data, double *px, double *py)
{
    if (data->trigger == 0)
    {
        if (data->pz[0] > 0 || data->pz[1] > 0)
            data->clr.color = data->clr.elevated;
        else
            data->clr.color = data->clr.base;
    }
    else if (data->trigger == 3)
    {
        if (data->pz[0] > data->pz[1] || data->pz[0] < data->pz[1])
            if (data->toggle == 1)
                data->clr.color = data->clr.elevated;
            else if (data->toggle == 2)
            {
                data->clr.color = data->clr.base;
                    if (px[0] < px[1] || py[0] > py[1])
                        data->clr.color = data->clr.base;
                    else if (px[0] < py[0] || px[1] > py[1])
                        data->clr.color = data->clr.base;
            }
            else
                data->clr.color += data->clr.elevated + data->clr.vertical;
        else if (data->pz[0] && data->pz[1])
                data->clr.color = data->clr.elevated;
        else if (px[0] < px[1] || py[0] > py[1])
                data->clr.color = data->clr.vertical;
        else if (px[0] < py[0] || px[1] > py[1])
                data->clr.color = data->clr.vertical;
        else
            data->clr.color = data->clr.vertical;
    }
    else if (data->trigger == 2)
        {
        if (data->pz[0] > data->pz[1] || data->pz[0] < data->pz[1])
            if (data->toggle == 1)
                data->clr.color = data->clr.base;
            else
                data->clr.color += data->clr.elevated + data->clr.vertical;
        else
            data->clr.color = data->clr.base;
    }
}

void    draw_line(t_data *data, double *px, double *py)
{
    data->pxls.deltax = px[1] - px[0];
    data->pxls.deltay = py[1] - py[0];
    data->pxls.pixels = sqrt((data->pxls.deltax * data->pxls.deltax)
            + (data->pxls.deltay * data->pxls.deltay));
    data->pxls.deltax /= data->pxls.pixels;
    data->pxls.deltay /= data->pxls.pixels;
    data->pxls.pixelx = px[0];
    data->pxls.pixely = py[0];
    pixel_color(data, px, py);
    while(data->pxls.pixels)
    {
        pixel_color(data, px ,py);
        mlx_pixel_put(data->arg.mlx, data->arg.win, data->pxls.pixelx + (WIDTH / 2) + data->slide, data->pxls.pixely + (HEIGHT / 4), data->clr.color);
        data->pxls.pixelx += data->pxls.deltax;
        data->pxls.pixely += data->pxls.deltay;
        --data->pxls.pixels;
    }
}

void    rotate_map(t_data *data, double *px, double *py, double *pz)
{
    double  *x;
    double  *y;
    
    x = px;
    y = py;
    *px = (*x - *y) / sqrt(2);
    *py = ((*x + (2 * *y)) - (*pz * data->elev)) / sqrt(6);
}