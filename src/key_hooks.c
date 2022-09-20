/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:28:33 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/20 21:45:01 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void toggle_zoom(int button, t_data *data)
{
    if (button == 24)
    {
        data->offset -= 40;
        data->gap += 4;
    }
    else if (button == 27)
    {
        data->offset +=40;
        data->gap -= 4;
    }
    else if (button == 126)
        data->elev += 2;
    else if (button == 125)
        data->elev -= 2;
    mlx_clear_window(data->arg.mlx, data->arg.win);
    draw_cols(data);
}

static void toggle_color(int button, t_data *data)
{
    if (button == 8)
    {
        data->clr.elevated += rgb_color(0.8, 0.2531, 0.2);
        data->clr.base += rgb_color(0.6, 0.92331, 0.7);
        data->clr.vertical += rgb_color(0.3, 1.1, 0.4);
    }
    else if (button == 17)
    {
        data->trigger = 2;
        data->toggle = 1;
        data->clr.elevated = rgb_color(1, 0.2531, 1);
        data->clr.base = rgb_color(1, 1, 1);
        data->clr.vertical = rgb_color(1, 0.81, 1);
    }
    else if (button == 9)
        data->toggle = 0;
    else if (button == 7)
    {
        data->toggle = 2;
        data->clr.base = rgb_color(1, 0.81, 0);
        data->clr.vertical = rgb_color(1, 1, 1);
        data->clr.elevated = rgb_color(1, 0.2531, 1);
    }
    else
        toggle_zoom(button, data);
    mlx_clear_window(data->arg.mlx, data->arg.win);
    draw_cols(data);
}

static void toggle_move(int button, t_data *data)
{
    if (button == 123)
    {
        data->trigger = 3;
        data->toggle = 1;
        data->clr.base = rgb_color(1, 1, 1);
        data->clr.vertical = rgb_color(1, 0.81, 0);
        data->clr.elevated = rgb_color(1, 0.2531, 1);
    }
    else if (button == 124)
        data->trigger = 0;
    else if (button == 13)
        data->offset -= 50;
    else if (button == 1)
        data->offset += 50;
    else if (button == 0)
        data->slide -= 50;
    else if (button == 2)
        data->slide += 50;
    else
        toggle_color(button, data);
    mlx_clear_window(data->arg.mlx, data->arg.win);
    draw_cols(data);
}

int toggle_button(int button, t_data *data)
{
    if (button == 53)
    {
        ft_putendl("You have exit the program");
        exit(EXIT_SUCCESS);
    }
    else if(button >= 0 && button <= 129)
    {
        ft_putnbr(button);
        ft_putchar('\n');
        toggle_move(button, data);
    }
    return (0);
}