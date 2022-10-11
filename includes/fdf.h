/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:17:50 by ahermawa          #+#    #+#             */
/*   Updated: 2022/10/05 13:39:45 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <fcntl.h>
# include "../libft/includes/libft.h"
# include <math.h>
# include <stdlib.h>
# include "mlx.h"

# define WIDTH 1980
# define HEIGHT 1080

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_pixls
{
	double	deltax;
	double	deltay;
	double	pixely;
	double	pixelx;
	int		pixels;
}				t_pixls;

typedef struct s_map
{
	int		rows;
	int		cols;
	int		**map;	
}				t_map;

typedef struct s_color
{
	int		color;
	int		base;
	int		elevated;
	int		vertical;
}				t_color;

typedef struct s_data
{
	t_mlx	arg;
	t_map	map;
	t_pixls	pxls;
	t_color	clr;
	int		i;
	int		j;
	int		offset;
	int		gap;
	int		slide;
	int		vslide;
	int		trigger;
	int		triggerc;
	int		elev;
	int		toggle;
	double	pz[2];
}				t_data;

int		rgb_color(double r, double g, double b);
int		toggle_button(int button, t_data *data);
void	read_map(char *filename, t_data *data);
void	draw_cols(t_data *data);
void	err_msg(int error, char *message);
void	draw_line(t_data *data, double *px, double *py);
void	init(t_data *data);
void	projection_iso(t_data *data, double *px, double *py, double *pz);
void	projection_cab(t_data *data, double *px, double *py, double *pz);
void	command_string(t_data *data);
void	check_err(t_data *data, int check, int i, int j);
void	data_color2(t_data *data, double *px, double *py);
void	data_color3(t_data *data, double *px, double *py);
void	toggle_keys(int button, t_data *data);
#endif
