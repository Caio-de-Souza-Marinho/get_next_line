#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	char	buffer[1000];
	int	read_return;
	int	offset = 0;

	for (int i = 0; i < 5; i++)
	{
		read_return = read(fd, buffer + offset, BUFFER_SIZE);
		offset += read_return;
	}

	buffer[offset] = '\0';
	close(fd);
	printf("fd = %d\n", fd);
	printf("read_return = %d\n", read_return);
	printf("buffer = %s\n", buffer);
	return (0);
}
