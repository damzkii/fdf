/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:49:08 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/24 18:39:01 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_color(t_data *data, double *px, double *py)
{
	if (data->trigger == 2)
		data_color2(data, px, py);
	else if (data->trigger == 3)
		data_color3(data, px, py);
	else if (data->trigger == 0)
	{
		if (data->pz[0] > 0 || data->pz[1] > 0)
			data->clr.color = data->clr.elevated;
		else
			data->clr.color = data->clr.base;
	}
}

int	map_too_big(double height, double width)
{
	if (height > HEIGHT)
		return (1);
	else if (width > WIDTH)
		return (1);
	else if (width < 0)
		return (1);
	else if (height < 0)
		return (1);
	return (0);
}

void	draw_line(t_data *data, double *px, double *py)
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
	while (data->pxls.pixels)
	{
		pixel_color(data, px, py);
		if (map_too_big(data->pxls.pixely + (HEIGHT / 4) + data->vslide,
				data->pxls.pixelx + (WIDTH / 2) + data->slide))
			break ;
		mlx_pixel_put(data->arg.mlx, data->arg.win, data->pxls.pixelx
			+ (WIDTH / 2) + data->slide, data->pxls.pixely
			+ (HEIGHT / 4) + data->vslide, data->clr.color);
		data->pxls.pixelx += data->pxls.deltax;
		data->pxls.pixely += data->pxls.deltay;
		--data->pxls.pixels;
	}
}

void	projection_iso(t_data *data, double *px, double *py, double *pz)
{
	double	*x;
	double	*y;

	x = px;
	y = py;
	*px = (*x - *y) / sqrt(2);
	*py = ((*x + (2 * *y)) - (*pz * data->elev)) / sqrt(6);
}

void	projection_cab(t_data *data, double *px, double *py, double *pz)
{
	double	*x;
	double	*y;
// hypotenuusa = a*a + b*b
	x = px;
	y = py;
	double a = px[1] - px[0];
	double b = py[1] - py[0];
	double alpha = sqrt(a * a + b * b);
	px[0] = (x[0] + (pz[0] * data->elev) / 2 * -cos(alpha));
	py[0] = (y[0] + (pz[0] * data->elev) / 2 * -sin(alpha));
	px[1] = (x[1] + (pz[1] * data->elev) / 2 * -cos(alpha));
	py[1] = (y[1] + (pz[1] * data->elev) / 2 * -sin(alpha));

	//projection_iso(data, &px[0], &py[0], &pz[0]);
	//projection_iso(data, &px[1], &py[1], &pz[1]);
}