/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:35:26 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/25 12:23:18 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_rows(t_data *data, double *px, double *py)
{
	data->pz[0] = data->map.map[data->j][data->i];
	data->pz[1] = data->map.map[data->j][data->i + 1];
	px[0] = data->offset + (data->i * data->gap);
	px[1] = data->offset + (data->i * data->gap) + data->gap;
	py[0] = data->offset + (data->j * data->gap);
	py[1] = data->offset + (data->j * data->gap);
	if (data->trigger)
	{
		projection_iso(data, &px[0], &py[0], &data->pz[0]);
		projection_iso(data, &px[1], &py[1], &data->pz[1]);
	}
	else if (data->triggerc)
	{
		projection_cab(data, &px[0], &py[0], &data->pz[0]);
		projection_cab(data, &px[1], &py[1], &data->pz[1]);
	}
}

void	draw_rows(t_data *data)
{
	double	px[3];
	double	py[3];

	data->j = -1;
	while (++data->j < data->map.rows)
	{
		data->i = -1;
		while (++data->i < data->map.cols - 1)
		{
			fill_rows(data, px, py);
			draw_line(data, px, py);
		}
	}
}

static void	fill_cols(t_data *data, double *px, double *py)
{
	data->pz[0] = data->map.map[data->j][data->i];
	data->pz[1] = data->map.map[data->j + 1][data->i];
	px[0] = data->offset + (data->i * data->gap);
	px[1] = data->offset + (data->i * data->gap);
	py[0] = data->offset + (data->j * data->gap);
	py[1] = data->offset + (data->j * data->gap) + data->gap;
	if (data->trigger)
	{
		projection_iso(data, &px[0], &py[0], &data->pz[0]);
		projection_iso(data, &px[1], &py[1], &data->pz[1]);
	}
	else if (data->triggerc)
	{
		projection_cab(data, &px[0], &py[0], &data->pz[0]);
		projection_cab(data, &px[1], &py[1], &data->pz[1]);
	}
}

void	draw_cols(t_data *data)
{
	double	px[3];
	double	py[3];

	data->j = -1;
	while (++data->j < data->map.rows - 1)
	{
		data->i = -1;
		while (++data->i < data->map.cols)
		{
			fill_cols(data, px, py);
			draw_line(data, px, py);
		}
	}
	command_string(data);
	draw_rows(data);
}
