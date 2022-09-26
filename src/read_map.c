/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:38:57 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/25 15:15:02 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_nbr(char **nbr)
{
	int	i;
	int	j;

	i = 0;
	while (nbr[i])
	{
		j = 0;
		if (nbr[i][j] == '-')
			j++;
		if (!ft_isdigit(nbr[i][j]))
			return (0);
		i++;
	}
	return (1);
}

static void	get_cols(char *filename, t_data *data)
{
	char	*line;
	char	**tmp;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		err_msg(1, "Missing File!");
	if (!(get_next_line(fd, &line)))
		err_msg(1, "Error");
	tmp = ft_strsplit(line, ' ');
	ft_free((void *)line, ft_strlen(line));
	if (!check_nbr(tmp))
		err_msg(1, "Invalid map_file");
	while (tmp[i])
		i++;
	ft_free_arr((void **)tmp, (size_t)i);
	data->map.cols = i;
	close(fd);
}

static void	get_rows(char *filename, t_data *data)
{
	char	*line;
	int		fd;
	int		ret;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		err_msg(1, "Error");
	ret = get_next_line(fd, &line);
	while (ret)
	{
		if (ret < 0)
			err_msg(1, "Error");
		i++;
		ft_free((void *)line, ft_strlen(line));
		ret = get_next_line(fd, &line);
	}
	data->map.rows = i;
	free(line);
	close(fd);
}

static void	assign_map(char *filename, t_data *data)
{
	char	*line;
	char	**tmp;
	int		fd;
	int		j;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		err_msg(1, "Error");
	data->i = 0;
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		j = -1;
		while (tmp[++j])
		{
			data->map.map[data->i][j] = ft_atoi(tmp[j]);
			check_err(data, 1, data->i, j);
		}
		ft_free((void *)line, ft_strlen(line));
		ft_free_arr((void **)tmp, (size_t)j);
		check_err(data, 2, data->i, j);
		data->i++;
	}
	ft_free((void *)line, ft_strlen(line));
	close(fd);
}

void	read_map(char *filename, t_data *data)
{
	int	i;

	get_cols(filename, data);
	get_rows(filename, data);
	data->map.map = (int **)malloc(sizeof(int *) * (data->map.rows + 1));
	if (!(data->map.map))
		err_msg(1, "Error");
	i = -1;
	while (++i < data->map.rows)
	{
		data->map.map[i] = (int *)malloc(sizeof(int) * data->map.cols);
		if (!data->map.map[i])
			err_msg(1, "Error");
	}
	assign_map(filename, data);
}
