/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:17:50 by ahermawa          #+#    #+#             */
/*   Updated: 2022/08/31 09:23:13 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <fcntl.h>
# include "../libft/includes/libft.h"
# include <math.h>
# include <stdlib.h>
//# include "../minilibx/mlx.h"

# define WIDTH 1980
# define HEIGHT 1280

typedef struct s_mlx
{
    void     *mlx;
    void     *win;
}               t_mlx;

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

typedef struct s_data
{
    t_mlx   arg;
    t_map   map;
    t_pixls pxls;
	int		i;
	int		j;
}				t_data;

void    read_map(char *filename, t_data *data);
void    err_msg(int error, char *message);
void draw_line(t_data *data, double *px, double *py);
#endif
