/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2016/02/03 11:11:57 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int			line_length(char *tmp)
{
	unsigned int	i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	return (i);
}

int							get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		**tmp;
	int				read_val;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!tmp)
	{
		if ((tmp = (char **)malloc(sizeof(char *) * 257)) == NULL)
			return (-1);
	}
	if (!(tmp[fd]))
	{
		if ((tmp[fd] = ft_strnew(0)) == NULL)
			return (-1);
	}
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
	tmp[fd] += line_length(tmp[fd]);
	return (read_val ? 1 : 0);
}
