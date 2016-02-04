/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2016/02/04 12:22:26 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// A SUPPRIMER
#include <string.h>
#include <stdio.h>
#include <string.h>

t_listfd		*ft_listfd(t_listfd *list_fst, int fd)
{
	t_listfd			*list_cur;

	ft_putstr("=====DEBUT FONCTION LISTFD====="); getchar();
	if (!list_fst)
	{
		ft_putstr("SI LISTFD N'EXISTE PAS..."); getchar();
		if ((list_fst = (t_listfd*)malloc(sizeof(t_listfd))) == NULL)
			return (NULL);
		list_fst->fd = fd;
		list_fst->tmp = ft_strnew(0);
		list_fst->next = NULL;
		return (list_fst);
	}
	list_cur = list_fst;
	ft_putstr("JE CHERCHE SI LE FD EXISTE..."); getchar();
	while (list_cur->next != NULL)
	{
		if (list_cur->fd == fd)
			return (list_cur);
		list_cur = list_cur->next;
	}
	ft_putstr("JE CREE SI J'AI PAS DE FD CORRESPONDANT"); getchar();
	// TODO: Verifier lassignation de list_cur et list_fst
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

static char 				*ft_realloc(char *ptr)
{
	char			*tmp;
	char			*tmp_nxt_line;

	tmp_nxt_line = ptr + line_length(ptr) + 1;
	tmp = ft_strnew(ft_strlen(tmp_nxt_line));
	tmp = ft_strcpy(tmp, tmp_nxt_line);
	free(ptr);
	return (tmp);
}

int					get_next_line(int const fd, char **line)
{
	static t_listfd		*listfd = NULL;
	char				buf[BUFF_SIZE + 1];
	int					read_val;


	ft_putstr("=====DEBUT FONCTION GNL====="); getchar();
	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if ((listfd = ft_listfd(listfd, fd)) == NULL)
		return (-1);
	ft_putstr("Valeur de fd en debut de fonction:\t\t"); ft_putnbr(fd); getchar();
	ft_putstr("Valeur de listfd->tmp en debut de fonction:\t"); ft_putstr(listfd->tmp); getchar(); // TEST
	while (!(ft_strchr(listfd->tmp, '\n')) && (read_val = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_val] = '\0';
		ft_putstr("Valeur de listfd->tmp dans la boucle1:\t\t"); ft_putstr(listfd->tmp); getchar(); //TEST
		listfd->tmp = ft_strjoin(listfd->tmp, buf);
		// REVIEW voir sil faut free ou pas ici, car join ne free pas
	}
	*line = ft_strsub(listfd->tmp, 0, line_length(listfd->tmp));
	if (ft_strchr(listfd->tmp, '\n'))
	{
		ft_putstr("Valeur de listfd->tmp dans le if1:\t\t"); ft_putstr(listfd->tmp); getchar(); //TEST
		listfd->tmp = ft_realloc(listfd->tmp);
		ft_putstr("Valeur de listfd->tmp dans le if2:\t\t"); ft_putstr(listfd->tmp); getchar(); //TEST
		// REVIEW strcpy pas bon pour les leaks comment free ?
	}
	ft_putstr("Valeur de read_val:\t\t\t\t"); ft_putnbr(read_val); getchar(); // TEST
	ft_putstr("Valeur de listfd->tmp en fin de fonction:\t"); ft_putstr(listfd->tmp); getchar(); //TEST
	return (read_val ? 1 : 0);
	/*
	 * if (read_val == 0)
	 * {
	 *
	 * }
	 * return (0);
	 */
}