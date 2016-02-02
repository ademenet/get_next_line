/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2016/02/02 15:25:15 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //A SUPPRIMER!

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
	static char		**tmp = NULL;
	char			buf[BUFF_SIZE + 1];
	int				read_val;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if ((tmp = (char **)malloc(sizeof(char *) * 257)) == NULL)
		return (-1);
	if (!(tmp[fd]) && ((tmp[fd] = ft_strnew(BUFF_SIZE)) == NULL))
		return (-1);
	while (!(ft_strchr(buf, '\n')) && (read_val = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp[fd] = ft_strjoin(tmp[fd], buf);
	}
	*line = ft_strsub(tmp[fd], 0, line_length(tmp[fd]));
	if (ft_strchr(buf, '\n'))
	{
		tmp[fd] = ft_strchr(buf, '\n');
		return (1);
	}
	tmp[fd] += line_length(tmp[fd]);
	return (read_val ? 1 : 0);
}
