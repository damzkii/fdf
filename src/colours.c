/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:59:00 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/24 12:50:02 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_color2(t_data *data, double *px, double *py)
{
	if (data->pz[0] > data->pz[1] || data->pz[0] < data->pz[1])
	{
		if (data->toggle == 1)
			data->clr.color = data->clr.base;
		else if (data->toggle == 2)
		{
			data->clr.color = data->clr.elevated;
			if (px[0] < px[1] || py[0] > py[1])
				data->clr.color = data->clr.elevated;
			else if (px[0] < py[0] || px[1] > py[1])
				data->clr.color = data->clr.elevated;
		}
		else if (data->toggle == 0)
			data->clr.color += data->clr.elevated + data->clr.vertical;
	}
	else if (data->pz[0] && data->pz[1])
		data->clr.color = data->clr.base;
	else if (px[0] < px[1] || py[0] > py[1])
		data->clr.color = data->clr.vertical;
	else if (px[0] < py[0] || px[1] > py[1])
		data->clr.color = data->clr.vertical;
	else
		data->clr.color = data->clr.vertical;
}

void	data_color3(t_data *data, double *px, double *py)
{
	if (data->pz[0] > data->pz[1] || data->pz[0] < data->pz[1])
	{
		if (data->toggle == 1)
			data->clr.color = data->clr.base;
		else if (data->toggle == 2)
		{
			data->clr.color = data->clr.elevated;
			if (px[0] < px[1] || py[0] > py[1])
				data->clr.color = data->clr.elevated;
			else if (px[0] < py[0] || px[1] > py[1])
				data->clr.color = data->clr.elevated;
		}
		else if (data->toggle == 0)
			data->clr.color += data->clr.elevated + data->clr.vertical;
	}
	else if (data->pz[0] && data->pz[1])
		data->clr.color = data->clr.base;
	else if (px[0] < px[1] || py[0] > py[1])
		data->clr.color = data->clr.vertical;
	else if (px[0] < py[0] || px[1] > py[1])
		data->clr.color = data->clr.vertical;
	else
		data->clr.color = data->clr.vertical;
}
