/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:49:08 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/05 16:29:59 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(t_data *data, double *px, double *py)
{
    data->pixls.deltax = px[1] - px[0];
    data->pixls.deltay = py[1] - py[0];
    data->pixls.pixels = sqrt((data->pixls.deltax * data->pixls.deltax)
            + (data->pixls.deltay * data->pixls.deltay);
    data->pixls.deltax /= data->pixls.pixels;
    data->pixls.deltay /= data->pixls.pixels;
    data->pixls.pixelx = px[0];
    data->pixls.pixely = py[0];
    while(data->pixls.pixels)
    {
        mlx_pixel_put(data->arg.mlx, data->arg.win, data->pixls.pxelx,
            data->pixls.pixely, data->color.clr)
        data->pixls.pixelx += data->pixls.deltax;
        data->pixls.pixely += data->pixls.deltay;
        --data->pixls.pixels;
    }
}