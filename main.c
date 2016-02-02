#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	**line;
	int		retour;

	line = (char**)malloc(sizeof(char*) * 100);
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY, 0555);
	retour = get_next_line(fd, line);
	while (retour > 0)
	{
		ft_putstr(*line);
		ft_putstr("\n");
		retour = get_next_line(fd, line);
	}
	return (0);
}
