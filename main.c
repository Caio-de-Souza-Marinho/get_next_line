/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:30:16 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/01 16:30:18 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
	{
		printf("file descriptor fucked");
		return (1);
	}
	while ((line = get_next_line(fd1)) != NULL )
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);
	while ((line = get_next_line(fd2)) != NULL )
	{
		printf("%s", line);
		free(line);
	}
	close(fd2);
	return (0);
}
