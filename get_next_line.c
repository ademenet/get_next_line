/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/30 15:35:32 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>

int		get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE];
	char			*tmp_previous;
	char			*tmp_next;
	static int		n;
	static int		i;

	while (read(fd, buf, BUFF_SIZE))
	{
		while (buf[i] != '\n')
		{
			i++;
		}
		if (buf[i] == '\0')
			tmp_previous = strndup(buf, i);
		tmp_next = strndup(buf, i);
		if (tmp_previous)
			line [n] = ft_strjoin(tmp_previous, tmp_next);
		return (1);
	}
	return (0);
}
