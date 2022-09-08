/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:35:26 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/08 16:23:29 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void fill_cols(t_data *data, double *px, double *py)
{
    px[0] = data->offset + (data->i * data->gap);
    px[1] = data->offset + (data->i * data->gap) + data-gap;
}
void    draw_map(t_data *data)
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
        }
    }    
}