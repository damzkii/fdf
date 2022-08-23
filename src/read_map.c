/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:38:57 by ahermawa          #+#    #+#             */
/*   Updated: 2022/08/23 14:25:40 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void get_cols_rows(char *filename, t_data *data, int rows)
{
    char    *line;
    char    **tmp;
    int     fd;
    int     i;

    i = 0
    fd = open(filename, O_RDONLY);
    if (!(get_next_line(filename, &line))
        err_msg(1, "Error!");
    tmp = ft_strsplit(line, ' ');
    while (tmp[i])
        i++;
    data->map.cols = i - 1;
    
    
    
}
void    read_map(char *filename)
{
    int     fd;
    int     j;

    get_cols_rows(filename, data, 0);
    
    
}