/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:54:44 by ademenet          #+#    #+#             */
/*   Updated: 2016/01/06 12:17:39 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/*typedef struct			s_listfd
{
	int					fd;
	char				save[BUFF_SIZE];
	int					i;
	struct s_listfd		*next;
}						t_listfd;*/

int					get_next_line(int const fd, char **line);
#endif
