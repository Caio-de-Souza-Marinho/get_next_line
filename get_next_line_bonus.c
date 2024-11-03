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

#include "get_next_line.h"

static char	*fill_line(int fd, char *stash, char *buffer);
static char	*set_line(char *line);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free(stash);
		free(buffer);
		stash = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = fill_line(fd, stash, buffer);
	free(buffer);
	buffer = NULL;
	if (line == NULL)
		return (NULL);
	stash = set_line(line);
	return (line);
}

static char	*fill_line(int fd, char *stash, char *buffer)
{
	char	*tmp;
	int		read_return;

	read_return = 1;
	while (read_return > 0)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (read_return == 0)
			break ;
		buffer[read_return] = '\0';
		if (stash == NULL)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

static char	*set_line(char *line)
{
	char	*stash;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[1] == '\0')
		return (NULL);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*stash == 0)
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}
