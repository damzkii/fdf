/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:39:01 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/24 17:21:09 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_msg(int error, char *message)
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

int	rgb_color(double r, double g, double b)
{
	int		color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

void	init(t_data *data)
{
	data->gap = 30;
	data->offset = 50;
	data->elev = 4;
	data->clr.base = rgb_color(1, 1, 1);
	data->clr.vertical = rgb_color(1, 0.81, 0);
	data->clr.elevated = rgb_color(1, 0.2531, 1);
	data->trigger = 0;
	data->slide = 0;
	data->toggle = 0;
	data->triggerc = 0;
}

void	check_err(t_data *data, int check, int i, int j)
{
	if (check == 1)
	{
		if (data->map.map[i][j] < -11000 && data->map.map[i][j] < 9000)
			err_msg(1, "Map values are too high or too low!");
	}
	else if (check == 2)
	{
		if (j != data->map.cols)
			err_msg(1, "Map width uneven");
	}
}

int	toggle_button(int button, t_data *data)
{
	if (button == 53)
	{
		ft_putendl("You have exit the program");
		exit(EXIT_SUCCESS);
	}
	else if (button >= 0 && button <= 129)
	{
		ft_putstr("key: ");
		ft_putnbr(button);
		ft_putchar('\n');
		toggle_keys(button, data);
	}
	return (0);
}
