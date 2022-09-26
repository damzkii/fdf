/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:28:33 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/26 14:33:47 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	toggle_keys5(int button, t_data *data)
{
	if (button == 6 && data->triggerc == 1)
	{
		data->triggerc = 0;
		data->elev = 0;
	}
	else if (data->trigger == 0)
	{
		if (button == 13)
			data->vslide -= 50;
		else if (button == 1)
			data->vslide += 50;
	}
	else
	{
		if (button == 13)
			data->offset -= 50;
		else if (button == 1)
			data->offset += 50;
	}
	mlx_clear_window(data->arg.mlx, data->arg.win);
	draw_cols(data);
}

void	toggle_keys4(int button, t_data *data)
{
	if (button == 24)
	{
		data->offset -= 40;
		data->gap += 4;
	}
	else if (button == 27)
	{
		data->offset += 40;
		data->gap -= 4;
	}
	else if (button == 126)
		data->elev += 4;
	else if (button == 125)
		data->elev -= 4;
	else if (button == 6 && data->triggerc == 0)
	{
		data->triggerc = 1;
		data->elev = 30;
	}
	else
		toggle_keys5(button, data);
	mlx_clear_window(data->arg.mlx, data->arg.win);
	draw_cols(data);
}

void	toggle_keys3(int button, t_data *data)
{
	if (button == 17)
	{
		data->trigger = 2;
		data->toggle = 1;
		data->clr.elevated = rgb_color(1, 1, 1);
		data->clr.base = rgb_color(1, 1, 1);
		data->clr.vertical = rgb_color(1, 1, 1);
	}
	else if (button == 9)
		data->toggle = 0;
	else if (button == 7)
	{
		data->toggle = 2;
		data->clr.base = rgb_color(1, 1, 1);
		data->clr.vertical = rgb_color(1, 0.81, 0);
		data->clr.elevated = rgb_color(1, 0.2531, 1);
	}
	else
		toggle_keys4(button, data);
	mlx_clear_window(data->arg.mlx, data->arg.win);
	draw_cols(data);
}

void	toggle_keys2(int button, t_data *data)
{
	if (button == 123)
	{
		data->trigger = 3;
		data->toggle = 1;
		data->clr.base = rgb_color(1, 1, 1);
		data->clr.vertical = rgb_color(1, 0.81, 0);
		data->clr.elevated = rgb_color(1, 0.2531, 1);
	}
	else if (button == 0)
		data->slide -= 50;
	else if (button == 2)
		data->slide += 50;
	else if (button == 124)
		data->trigger = 0;
	else
		toggle_keys3(button, data);
	mlx_clear_window(data->arg.mlx, data->arg.win);
	draw_cols(data);
}

void	toggle_keys(int button, t_data *data)
{
	if (button == 8)
	{
		if (data->toggle == 1)
		{
			data->clr.base += rgb_color(0.6, 0.92331, 0.7);
			data->clr.vertical += rgb_color(0.6, 0.92331, 0.7);
		}
		else
		{
			data->clr.elevated += rgb_color(0.8, 0.2531, 0.2);
			data->clr.base += rgb_color(0.6, 0.92331, 0.7);
			data->clr.vertical += rgb_color(0.3, 1.1, 0.4);
		}
	}
	else
		toggle_keys2(button, data);
	mlx_clear_window(data->arg.mlx, data->arg.win);
	draw_cols(data);
}
