/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2016/02/03 17:20:05 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// A SUPPRIMER
#include <string.h>
#include <stdio.h>

t_listfd		*ft_listfd(t_listfd *list_fst, int fd)
{
	t_listfd			*list_cur;

	if (!list_fst)
	{
		if ((list_fst = (t_listfd*)malloc(sizeof(t_listfd))) == NULL)
			return (NULL);
		list_fst->fd = fd;
		list_fst->tmp = ft_strnew(0);
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
	// TODO: Verifier lassignation de list_cur et list_fst
	if ((list_cur = (t_listfd*)malloc(sizeof(t_listfd))) == NULL)
		return (NULL);
	list_cur->next = list_fst;
	list_cur->tmp = ft_strnew(0);
	list_fst = list_cur;
	return (list_fst);
}

/*
 * static char			*ft_join_current(t_listfd *listfd, char *buf)
 * {
 * 	int					i;
 *
 * 	i = 0;
 * 	line[i] = ft_strjoin();
 * }
 */

/*
 * static int			ft_read(t_listfd *listfd, char **line)
 * {
 * 	int					i;
 * 	int					ret;
 * 	char				buf[BUFF_SIZE];
 * 	char				tmp;
 *
 * 	ft_memset(buf, '\0', BUFF_SIZE);
 * 	if (ft_strlen(listfd->tmp) > 0)
 * 	{
 * 		if ((tmp = (char*)malloc(sizeof(char) * ft_strlen(listfd->tmp)))
 * 				== NULL)
 * 			return (-1);
 * 		ft_strcpy(tmp, listfd->tmp);
 * 	}
 * 	i = 0;
 * 	while ((ret = read(listfd->fd, buf, BUFF_SIZE))  != -1)
 * 	{
 * 		//CA NE VAS PAS DU TOUT !
 * 		while (buf[i] != '\n')
 * 		{
 * 			line[i] = ft_strjoin(tmp, buf);
 * 			if ((tmp = (char*)malloc(sizeof(char) * ft_strlen(line[i])))
 * 					== NULL)
 * 				return (-1);
 * 			//coller buf
 * 		}
 * 	}
 * 	return (-1);
 * }
 */
 static unsigned int			line_length(char *tmp)
 {
 	unsigned int	i;

 	i = 0;
 	while (tmp[i] != '\n' && tmp[i] != '\0')
 		i++;
 	return (i);
 }

int					get_next_line(int const fd, char **line)
{
	static t_listfd		*listfd = NULL;
	char				buf[BUFF_SIZE + 1];
	int					read_val;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	// Je regarde si list_fd existe et je traite
	if ((listfd = ft_listfd(listfd, fd)) == NULL)
		return (-1);
	while (!(ft_strchr(listfd->tmp, '\n')) && (read_val = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_val] = '\0';
		listfd->tmp = ft_strjoin(listfd->tmp, buf);
		// REVIEW voir sil faut free ou pas ici, car join ne free pas
	}
	*line = ft_strsub(listfd->tmp, 0, line_length(listfd->tmp));
	if (ft_strchr(listfd->tmp, '\n'))
	{
		listfd->tmp = ft_strcpy(listfd->tmp, ft_strchr(listfd->tmp, '\n') + 1);
		// REVIEW strcpy pas bon pour les leaks comment free ?
	}
	return (read_val ? 1 : 0);
}