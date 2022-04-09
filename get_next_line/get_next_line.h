/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:39:18 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/09 18:45:30 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_file
{
	int				fd;
	int				newline;
	int				eof;
	ssize_t			len;
	char			*content;
	struct s_file	*next;
}	t_file;

char	*get_next_line(int fd);
char	*read_buffer(t_file **file);

ssize_t	find_newline(t_file **file);

t_file	*t_malloc(int fd);
void	*free_fdfile(t_file **file);
#endif
