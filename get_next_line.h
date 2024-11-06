/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:45:27 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/06 18:25:34 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;

char		*get_next_line(int fd);
void		create_list(t_list **list, int fd);
int			found_newline(t_list *list);
void		append(t_list **list, char *buf);
t_list		*find_last_node(t_list *list);
char		*set_line(t_list *list);
int			len_until_newline(t_list *list);
void		copy_str(t_list *list, char *str);
void		clean_list(t_list **list);
void		dealloc(t_list **list, t_list *clean_node, char *buf);

#endif
