/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2016/02/02 19:05:58 by ademenet         ###   ########.fr       */
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

// Probleme : lorsque la fonction est rappelee tmp[fd] se reinitialise
// le static ne fonctionne pas
int							get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		**tmp;
	int				read_val;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!tmp)
	{
		ft_putstr("je cree tmp"); ft_putstr("\n"); getchar();
		if ((tmp = (char **)malloc(sizeof(char *) * 257)) == NULL)
			return (-1);
	}
	if (!(tmp[fd]))
	{
		ft_putstr("je cree tmp[fd]"); ft_putstr("\n"); getchar();
		if ((tmp[fd] = ft_strnew(0)) == NULL)
			return (-1);
	}
	ft_putstr("tmp[fd] avant la boucle:"); ft_putstr(tmp[fd]); ft_putstr("\n"); getchar();

	while (!(ft_strchr(tmp[fd], '\n')) && (read_val = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_val] = '\0';
		ft_putstr("tmp[fd] avant le join:"); ft_putstr(tmp[fd]); ft_putstr("\n"); getchar();
		tmp[fd] = ft_strjoin(tmp[fd], buf);
		ft_putstr("tmp[fd] apres le join:"); ft_putstr(tmp[fd]); ft_putstr("\n"); getchar();
	}
	*line = ft_strsub(tmp[fd], 0, line_length(tmp[fd]));
	if (ft_strchr(buf, '\n'))
	{
		ft_putstr("tmp[fd] avant le strchr:"); ft_putstr(tmp[fd]); ft_putstr("\n"); getchar();
		tmp[fd] = ft_strchr(buf, '\n') + 1;
		ft_putstr("tmp[fd] apres le strchr:"); ft_putstr(tmp[fd]); ft_putstr("\n"); getchar();
		return (1);
	}
	tmp[fd] += line_length(tmp[fd]);
	ft_putstr("tmp[fd] juste avant la fin:"); ft_putstr(tmp[fd]); ft_putstr("\n"); getchar();
	return (read_val ? 1 : 0);
}
