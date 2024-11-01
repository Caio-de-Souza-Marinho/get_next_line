/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:45:27 by caide-so          #+#    #+#             */
/*   Updated: 2024/10/29 20:45:33 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef GET_NEXT_LINE_H 
#define GET_NEXT_LINE_H

char	*get_next_line(int fd);
#ifdef BUFFER_SIZE
#endif

#endif
