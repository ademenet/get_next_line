/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/30 19:09:18 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>

t_list		*ft_lstnew(char *buf)
{
	t_list	*list;

	if (!(list = (t_list*)ft_memalloc(sizeof(t_list))));
		return (NULL);
	if (buf)
	{
		ft_memcpy(list->buf, buf, BUFF_SIZE);
	}
}

int		get_next_line(int const fd, char **line)
{
	static char			buf[BUFF_SIZE];
	size_t				rtrn;

	while ((rtrn = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rtrn] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			ft_one_line();
			return (1);
		}
		else
		{

		}
	}
}
