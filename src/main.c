/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:27:17 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/16 19:12:57 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc,char **argv)
{
    t_data  data;
    
    if (argc != 2)
            err_msg(0, "Usage: ./fdf <filename>");
    init(&data);
    read_map(argv[1], &data);
    data.arg.mlx = mlx_init();
    data.arg.win = mlx_new_window(data.arg.mlx, WIDTH, HEIGHT, "FDF Project");
    draw_cols(&data);
    mlx_loop(data.arg.mlx);
    //sleep (5);
    return (0);
}
