/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:35:26 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/16 17:06:07 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void fill_rows(t_data *data, double *px, double *py)
{
    px[0] = data->offset + (data->i * data->gap);
    px[1] = data->offset + (data->i * data->gap) + data->gap;
    py[0] = data->offset + (data->j * data->gap);
    py[1] = data->offset + (data->j * data->gap);
    
}
void    draw_rows(t_data *data)
{
    double px[3];
    double py[3];

    data->j = -1;
    while(++data->j < data->map.cols)
    {
        data->i = -1;
        while(++data->i < data->map.rows)
        {
            fill_rows(data, px, py);
            draw_line(data, px, py);
        }
    }
}
static void fill_cols(t_data *data, double *px, double *py)
{
    //data->pz[0] = data->map.map[data->j][data->i];
    //data->pz[1] = data->map.map[data->j + 1][data->i];
    px[0] = data->offset + (data->i * data->gap);
    px[1] = data->offset + (data->i * data->gap);
    py[0] = data->offset + (data->j * data->gap);
    py[1] = data->offset + (data->j * data->gap) + data->gap;
       
}
void    draw_cols(t_data *data)
{
    double  px[3];
    double  py[3];
    
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
    draw_rows(data);
}