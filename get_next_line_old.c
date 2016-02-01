/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2016/01/06 15:55:46 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>

static t_listfd		*ft_listfd(t_listfd *list_fst, int fd, char *save)
{
	t_listfd			*list_cur;

	if (!list_fst)
	{
		if ((list_fst = (t_listfd*)malloc(sizeof(t_listfd))) == NULL)
			return (NULL);
		list_fst->fd = fd;
		ft_memset(list_fst->save, '\0', BUFF_SIZE);
		list_fst->next = NULL;
		return (list_fst);
	}
	list_cur = list_fst;
	while (list_cur->next != NULL)
	{
		if (list_cur->fd == fd)
			return (list_cur);
		list_cur = list_cur->next;
	}
	//verifier lassignation de list_cur et list_fst
	if ((list_cur = (t_listfd*)malloc(sizeof(t_listfd))) == NULL)
		return (NULL);
	list_cur->next = list_fst;
	ft_memset(list_cur->save, '\0', BUFF_SIZE);
	return (list_fst);
}

static char			*ft_join_current(t_listfd *listfd, char *buf)
{
	int					i;

	i = 0;
	line[i] = ft_strjoin();
}

static int			ft_read(t_listfd *listfd, char **line)
{
	int					i;
	int					ret;
	char				buf[BUFF_SIZE];
	char				tmp;

	ft_memset(buf, '\0', BUFF_SIZE);
	if (ft_strlen(listfd->save) > 0)
	{
		if ((tmp = (char*)malloc(sizeof(char) * ft_strlen(listfd->save)))
				== NULL)
			return (-1);
		ft_strcpy(tmp, listfd->save);
	}
	i = 0;
	while ((ret = read(listfd->fd, buf, BUFF_SIZE))  != -1)
	{
		//CA NE VAS PAS DU TOUT !
		while (buf[i] != '\n')
		{
			line[i] = ft_strjoin(tmp, buf);
			if ((tmp = (char*)malloc(sizeof(char) * ft_strlen(line[i])))
					== NULL)
				return (-1);
			//coller buf
		}
	}
	return (-1);
}

int					get_next_line(int const fd, char **line)
{
	static t_listfd		*listfd;
	char				*save;

	if (fd < 0 || BUFF_SIZE <= 0 || **line == NULL)
		return (-1);
	if ((listfd = ft_listfd(listfd, fd, save)) == NULL)
		return (-1);
	if (ft_read(listfd, line))
		return (1);
	return (0);
}
