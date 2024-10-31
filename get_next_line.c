/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:35:24 by caide-so          #+#    #+#             */
/*   Updated: 2024/10/28 18:35:41 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{

/* buffer - place where the read function stores the bytes it read. */
	char	*buffer;
/* stash - static variable that keeps its value between function calls */
	static char	*stash;
/* line - value to return */
	char	*line;

/* use read() to read the file descriptor passed as parameter and*/
	int	read_return;
	read_return = read(fd, buffer, BUFFER_SIZE);
/* put buffer in the stash */
	stash = ft_strdup(buffer);
	/* if there is a '\n' in the stash */
		/* extract the line until the '\n' */
		/* clean stash */
		/* return the line */
	/* else */
		/* keep reading the file */
		/* append buffer to the stash */
	return (line);
}
