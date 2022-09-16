/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:49:08 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/16 19:19:51 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(t_data *data, double *px, double *py)
{
    data->pxls.deltax = px[1] - px[0];
    data->pxls.deltay = py[1] - py[0];
    data->pxls.pixels = sqrt((data->pxls.deltax * data->pxls.deltax)
            + (data->pxls.deltay * data->pxls.deltay));
    data->pxls.deltax /= data->pxls.pixels;
    data->pxls.deltay /= data->pxls.pixels;
    data->pxls.pixelx = px[0];
    data->pxls.pixely = py[0];
    while(data->pxls.pixels)
    {
        mlx_pixel_put(data->arg.mlx, data->arg.win, (WIDTH / 2) + data->dir, data->pxls.pixely + (HEIGHT / 4), data->clr.color);
        data->pxls.pixelx += data->pxls.deltax;
        data->pxls.pixely += data->pxls.deltay;
        --data->pxls.pixels;
    }
}