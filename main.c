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
	int	fd1;
	int	fd2;
	int	fdi = 3;
	int	i = 0;
	char	*line;

	fd1 = open("test_files/big_line_no_nl.txt", O_RDONLY);
	fd2 = open("test_files/big_line_with_nl.txt", O_RDONLY);
	printf("fd1 = %d\n", fd1);
	printf("fd2 = %d\n", fd2);

	printf("START OF FILE %d\n", fdi);
	while ((line = get_next_line(fd1)) != NULL )
	{
		printf("Line %d >>> %s", i++, line);
		free(line);
	}
	printf("END OF FILE %d\n", fdi++);
	close(fd1);
	i = 0;
	
	printf("START OF FILE %d\n", fdi);
	while ((line = get_next_line(fd2)) != NULL )
	{
		printf("Line %d >>> %s", i++, line);
		free(line);
	}
	printf("END OF FILE %d\n", fdi++);
	close(fd2);
	i = 0;
	return (0);
}
