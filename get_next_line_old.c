/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2016/02/04 09:15:09 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>// A RETIRER

#include "get_next_line.h"

static unsigned int			line_length(char *tmp)
{
	unsigned int	i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	return (i);
}

static char					**allocation(char **tmp, int fd)
{
	char	**tmp_;

	tmp_ = tmp;
	if (!tmp_)
	{
		if ((tmp_ = (char **)malloc(sizeof(char *) * 257)) == NULL)
			return (NULL);
	}
	if (!(tmp_[fd]))
	{
		if ((tmp_[fd] = ft_strnew(0)) == NULL)
			return (NULL);
	}
	return (tmp_);
}

int							get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		**tmp;
	int				read_val;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if ((tmp = allocation(tmp, fd)) == NULL)
		return (-1);
	while (!(ft_strchr(tmp[fd], '\n')) && (read_val = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_val] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buf);
	}
	*line = ft_strsub(tmp[fd], 0, line_length(tmp[fd]));
	if (ft_strchr(tmp[fd], '\n'))
	{
		tmp[fd] = ft_strcpy(tmp[fd], ft_strchr(tmp[fd], '\n') + 1);
		return (1);
	}
	// ft_putnbr(line_length(tmp[fd])); getchar(); //TEST
	// ft_putnbr(read_val); getchar(); //TEST
	// ft_putstr(tmp[fd]); getchar(); //TEST
	*line = tmp[fd];
	// tmp[fd] += line_length(tmp[fd]);
	return (line_length(tmp[fd]) ? 1 : 0);
}