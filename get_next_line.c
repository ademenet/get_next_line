/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2016/02/04 18:58:50 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_listfd					*ft_listfd(t_listfd *list_fst, int fd)
{
	t_listfd			*list_cur;

	list_cur = list_fst;
	if (list_cur)
	{
		while (list_cur->next != NULL)
		{
			if (list_cur->fd == fd)
				return (list_cur);
			list_cur = list_cur->next;
		}
	}
	if ((list_cur = (t_listfd*)malloc(sizeof(t_listfd))) == NULL)
		return (NULL);
	list_cur->next = list_fst;
	list_cur->tmp = ft_strnew(0);
	list_fst = list_cur;
	return (list_fst);
}

static unsigned int			line_length(char *tmp)
{
	unsigned int	i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	return (i);
}

static char					*ft_realloc(char *ptr)
{
	char			*tmp;
	char			*tmp_nxt_line;

	tmp_nxt_line = ptr + line_length(ptr) + 1;
	tmp = ft_strnew(ft_strlen(tmp_nxt_line));
	tmp = ft_strcpy(tmp, tmp_nxt_line);
	free(ptr);
	return (tmp);
}

static int					ft_check_line(char *tmp)
{
	if (ft_strchr(tmp, '\n'))
	{
		tmp = ft_realloc(tmp);
		return (1);
	}
	if (ft_strlen(tmp) > 0)
	{
		tmp = ft_realloc(tmp);
		return (1);
	}
	return (0);
}

int							get_next_line(int const fd, char **line)
{
	static t_listfd		*listfd = NULL;
	t_listfd			*listfd_fst;
	char				buf[BUFF_SIZE + 1];
	int					read_val;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	listfd_fst = listfd ? listfd : NULL;
	listfd = ft_listfd(listfd_fst, fd);
	while (!(ft_strchr(listfd->tmp, '\n')) &&
			(read_val = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_val] = '\0';
		listfd->tmp = ft_strjoin(listfd->tmp, buf);
	}
	*line = ft_strsub(listfd->tmp, 0, line_length(listfd->tmp));
	return (ft_check_line(listfd->tmp));
}
