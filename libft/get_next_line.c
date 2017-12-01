/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:40:29 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/22 15:18:55 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memory(char **rest, int bts, char *buf)
{
	char *ptr;
	char *ptr2;

	ptr = *rest;
	if (bts < BUFF_SIZE)
	{
		ptr2 = ft_strsub(buf, 0, bts);
		*rest = ft_strjoin(*rest, ptr2);
		free(ptr2);
	}
	else
		*rest = ft_strjoin(*rest, buf);
	free(ptr);
	return (*rest);
}

char	*ft_initialize(char **rest, char **line, char *chr)
{
	*line = ft_strsub(*rest, 0, chr - *rest);
	return (*rest);
}

int		ft_read_write(int fd, char **rest, char **line)
{
	t_vault		s;

	ft_bzero(s.buf, BUFF_SIZE + 1);
	while ((!(s.chr = ft_strchr(*rest, '\n'))) > 0)
		if ((s.bts = read(fd, s.buf, BUFF_SIZE)) > 0)
			*rest = ft_memory(rest, s.bts, s.buf);
		else if (s.bts == 0)
		{
			*line = ft_strdup(*rest);
			free(*rest);
			*rest = ft_strnew(0);
			if (*line[0] != '\0')
				return (1);
			break ;
		}
		else if (s.bts < 0)
			return (-1);
	if (*rest[0] != '\0')
	{
		s.ptr = ft_initialize(rest, line, s.chr);
		*rest = ft_strdup(s.chr + 1);
		free(s.ptr);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	t_lst	*lst;
	t_lst			*tp;

	if (fd < 0)
		return (-1);
	tp = lst;
	while (tp)
	{
		if (tp->fd == fd)
			return (ft_read_write(tp->fd, &tp->rest, line));
		tp = tp->next;
	}
	tp = (t_lst *)malloc(sizeof(t_lst));
	tp->fd = fd;
	tp->rest = ft_strnew(0);
	tp->next = lst;
	lst = tp;
	return (ft_read_write(tp->fd, &tp->rest, line));
}
