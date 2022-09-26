/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:27:17 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/26 14:22:43 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_program(t_data *data)
{
	mlx_clear_window(data->arg.mlx, data->arg.win);
	mlx_destroy_window(data->arg.mlx, data->arg.win);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		err_msg(0, "Usage: ./fdf <filename>");
	init(&data);
	read_map(argv[1], &data);
	data.arg.mlx = mlx_init();
	if (!(data.arg.mlx))
		err_msg(0, "Initialize failed");
	data.arg.win = mlx_new_window(data.arg.mlx, WIDTH, HEIGHT, "FDF Project");
	if (!(data.arg.win))
		err_msg(0, "Creating window failed");
	mlx_hook(data.arg.win, 2, 1L << 0, &toggle_button, &data);
	mlx_hook(data.arg.win, 17, 0, &close_program, &data);
	draw_cols(&data);
	mlx_loop(data.arg.mlx);
	return (0);
}
