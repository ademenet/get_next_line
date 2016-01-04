/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2016/01/04 13:57:58 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>

static t_list		*ft_listfd(t_list *list_fst, int fd, char *save)
{
	t_list	*list_cur;

	if (!list_fst)
	{
		if ((list_fst = (t_list*)malloc(sizeof(t_list))) == NULL)
					return (NULL);
		list_fst->fd = fd;
		memset(list_fst->save, '\0', BUFF_SIZE);
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
	if ((list_cur = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list_cur->next = list_fst;
	memset(list_cur->save, '\0', BUFF_SIZE);
	return (list_fst);
}

int					get_next_line(int const fd, char **line)
{
	static t_list		*listfd;
	char				*save;

	listfd = ft_listfd(listfd, fd, save);
}
