/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:21:49 by ahermawa          #+#    #+#             */
/*   Updated: 2022/05/13 13:59:16 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read_line(const int fd, char **stash)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (*stash == NULL)
			*stash = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(*stash, buf);
			free(*stash);
			*stash = tmp;
		}
		if (ft_strchr(*stash, '\n'))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (ret);
}

static int	ft_fill_line(char **s, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\n')
	{
		*line = ft_strsub(*s, 0, i);
		tmp = ft_strdup(&(*s)[i + 1]);
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	ft_error_check(int fd, char **line, char **s, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (ft_fill_line(&s[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	static char		*s[FD_SIZE];
	int				ret;

	if (fd < 0 || fd >= FD_SIZE || BUFF_SIZE < 1 || !line)
		return (-1);
	if (s[fd])
		if (ft_strchr(s[fd], '\n'))
			return (ft_fill_line(&s[fd], line));
	ret = ft_read_line(fd, &s[fd]);
	return (ft_error_check(fd, line, s, ret));
}
