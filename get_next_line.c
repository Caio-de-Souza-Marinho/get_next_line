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

/* buffer - place where the read function stores the bytes it read. */
/* stash - static variable that keeps its value between function calls */
/* line - value to return */

/* use read() to read the file descriptor passed as parameter and*/
/* put buffer in the stash */
	/* if there is a '\n' in the stash */
		/* extract the line until the '\n' */
		/* clean stash */
		/* return the line */
	/* else */
		/* keep reading the file */
		/* append buffer to the stash */

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE];
	int			read_return;

	read_return = read(fd, buffer, BUFFER_SIZE);
	if (read_return <= 0)
		return (NULL);
	buffer[read_return] = '\0';
	stash = ft_strdup(buffer);
	return (stash);
}
