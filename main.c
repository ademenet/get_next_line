#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line[100];

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY, 0555);
	printf("%d\n", fd);
	get_next_line(fd, line);
	ft_putstr("Apres le GNL"); getchar();
	ft_putstr(line[0]);
	ft_putstr("Apres le pustr");
	return (0);
}