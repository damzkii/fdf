/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:44:15 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/25 14:02:31 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	command_string2(t_data *data)
{
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 180,
		0xFFFFF, "    +       : Zoom in");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 200,
		0xFFFFF, "    -       : Zoom out");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 220,
		0xFFFFF, "    T       : Toggle to one solid color 3D Iso");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 240,
		0xFFFFF, "    X       : Toggle to three solid color 3D Iso");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 260,
		0xFFFFF, "    C       : Change color");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 280,
		0xFFFFF, "    V       : Shaded vertical lines");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 300,
		0xFFFFF, "  T or <-   : Toggles back to solid vertical lines");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 330,
		0xFFFFFF, "Esc: Exit the program");
}

void	command_string(t_data *data)
{
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 30,
		0xFFFFFF, "Commands:");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 60,
		0xFFFFF, "Move map    : W A S D");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 80,
		0xFFFFF, "Arrow left  : Toggle two solid color 3D Iso");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 100,
		0xFFFFF, "Arrow up    : Elevates 3D");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 120,
		0xFFFFF, "Arrow down  : Delevates 3D");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 140,
		0xFFFFF, "Arrow right : Toggles back to 2D");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 160,
		0xFFFFF, "    Z       : Toggles 2D to 3D cabinet");
	command_string2(data);
}
