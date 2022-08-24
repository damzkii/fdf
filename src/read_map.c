/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:38:57 by ahermawa          #+#    #+#             */
/*   Updated: 2022/08/24 17:00:05 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void get_cols(char *filename, t_data *data)
{
    char    *line;
    char    **tmp;
    int     fd;
    int     i;

    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        err_msg(1, "Error!");
    if (!(get_next_line(fd, &line)))
        err_msg(1, "Error!");
    tmp = ft_strsplit(line, ' ');
    while (tmp[i])
        i++;
    ft_free_arr(tmp, (size_t)i);
    data->map.cols = i;
    free(line);
    close(fd);   
}

static void get_rows(char *filename, t_data *data)
{
    char    *line;
    int     fd;
    int     ret;
    int     i;

    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        err_msg(1, "Error!");
    ret = get_next_line(fd, &line);
    while (ret)
    {
        if (ret < 0)
            err_msg(1, "Error!");
        i++;
        ret = get_next_line(fd, &line);
    }
    data->map.rows = i;
    free(line);
    close(fd);
}

static void assign_map(char *filename, t_data *data)
{
    char    *line;
    char    **tmp;
    int     fd;
    int     i;
    int     j;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        err_msg(1, "Error!");
    i = 0;
    while (get_next_line(fd, &line))
    {
        tmp = ft_strsplit(line, ' ');
        j = -1;
        while (tmp[++j])
        {
            data->map.map[i][j] = ft_atoi(tmp[j]);
            if (data->map.map[i][j] < -11000 && data->map.map[i][j] < 9000)
                err_msg(1, "Map values are too high or too low!");
        }
        ft_free_arr(tmp, (size_t)j);
        if ((j - 1) != data->map.cols)
            err_msg(1, "Map width uneven");
        i++;      
    }
    free(line);
    close(fd);
}

void    read_map(char *filename, t_data *data)
{
    int     i;
    
    get_cols(filename, data);
    get_rows(filename, data);
    data->map.map = (int **)malloc(sizeof(int *) * (data->map.rows + 1));
    if (!(data->map.map))
        err_msg(1, "Errors!");
    i = -1;
    while (++i <= data->map.rows)
    {
        data->map.map[i] = (int *)malloc(sizeof(int) * (data->map.cols));
        if (!(data->map.map[i]))
            err_msg(1, "Error!");
    }
    assign_map(filename, data);
    printf("%d", data->map.cols);
    printf("%d", data->map.rows);
}