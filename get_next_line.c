/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:53:51 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/29 19:08:39 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	char	buf[BUFF_SIZE];
	int		n;

	read(fd, buf, BUFF_SIZE);
	n = 0;
	while (buf[n] != '\n')
		n++;

}
