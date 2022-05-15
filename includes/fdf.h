/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:17:50 by ahermawa          #+#    #+#             */
/*   Updated: 2022/05/15 16:54:30 by ahermawa         ###   ########.fr       */
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

typedef struct s_data
{
    t_mlx   arg;
    
}
#endif