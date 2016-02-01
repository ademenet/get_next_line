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

#include <stdio.h> //A SUPPRIMER!

#include "get_next_line.h"

static int			line_length(char *tmp)
{
	int				i;

	i = 0;
	while (tmp[i] != '\n' || tmp[i] != '\0')
		i++;
	return (i);
}

int					get_next_line(int const fd, char **line)
{
	static char		**tmp = NULL;
	char			buf[BUFF_SIZE + 1];
	int				read_val;

	ft_putstr("Debut de gnl"); getchar();
	if (fd < 0 || BUFF_SIZE <= 0 || !line)
	{
		ft_putstr("Il y a une couille dans le potage"); getchar();
		return (-1);
	}
	if ((tmp = (char **)malloc(sizeof(char *) * 256)) == NULL)
	{
		ft_putstr("J'ai pas reussi a malloc tmp"); getchar();
		return (-1);
	}
	if (!(tmp[fd]))
	{
		ft_putstr("tmp[fd] n'existe pas, je vais le creer"); getchar();
		if ((tmp[fd] = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
			return (-1);
		ft_putstr("J'ai cree tmp[fd]"); getchar();
	}
	ft_putstr("Avant le while"); getchar();
	while (!ft_strchr(buf, '\n') &&
		(read_val = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_putstr("Debut de la boucle"); getchar();
		tmp[fd][BUFF_SIZE] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buf);
		ft_putstr("tmp[fd] = "); ft_putstr(tmp[fd]); getchar();
	}
	*line = ft_strsub(tmp[fd], 0, line_length(tmp[fd]));
	ft_putstr(*line); getchar();
	if (ft_strchr(buf, '\n'))
	{
		tmp[fd] = ft_strchr(buf, '\n');
		return (1);
	}
	return (read_val ? 1 : 0);
}