#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	return (0);
}
