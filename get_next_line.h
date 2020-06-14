/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:32:14 by kdustin           #+#    #+#             */
/*   Updated: 2020/06/13 22:51:49 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		free_return_error(char **str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*remalloc(char *str, const char *buf, int actl_buf_len);
char	*ft_strdup(const char *s1);
char	*cut_first_line(char **str);

// # ifdef BUFFER_SIZE < 1
// 	# error BUFFER_SIZE is too big
// # elif BUFFER_SIZE > SSIZE_MAX
// 	# undef BUFFER_SIZE
// 	# define BUFFER_SIZE 1
// # endif
# ifndef BUFFER_SIZE
	# define BUFFER_SIZE 1
# endif

#endif
