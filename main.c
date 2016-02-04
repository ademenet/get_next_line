#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	**line1;
	char	**line2;
	int		retour1;
	int		retour2;

	line1 = (char**)malloc(sizeof(char*) * 100);
	line2 = (char**)malloc(sizeof(char*) * 100);
	if (argc > 3)
		return (0);
	fd1 = open(argv[1], O_RDONLY, 0555);
	fd2 = open(argv[2], O_RDONLY, 0555);
	retour1 = get_next_line(fd1, line1);
	retour2 = get_next_line(fd2, line2);
	while (retour1 > 0)
	{
		ft_putstr(*line1);
		ft_putstr("\n");
		retour1 = get_next_line(fd1, line1);
		ft_putstr(*line2);
		ft_putstr("\n");
		retour2 = get_next_line(fd2, line2);
	}
	return (0);
}