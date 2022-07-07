/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:17:50 by ahermawa          #+#    #+#             */
/*   Updated: 2022/07/07 15:06:44 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <fcntl.h>
# include "libft/libft.h"
# include <math.h>
# include "../minilibx/mlx.h"

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
#endif
