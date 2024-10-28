#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	// abrir um arquivo e ler seu conteudo
	int	fd = open("test.txt", O_WRONLY);
	char	buffer[4];
	int	read_return = read(fd, buffer, 5);
	close(fd);
	printf("fd = %d\n", fd);
	printf("read_return = %d\n", read_return);
	printf("buffer = %s\n", buffer);
}
