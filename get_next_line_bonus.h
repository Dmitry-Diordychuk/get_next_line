/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:32:14 by kdustin           #+#    #+#             */
/*   Updated: 2020/06/21 17:36:49 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# if BUFFER_SIZE < 1
#  error wrong BUFFER_SIZE
# elif BUFFER_SIZE > SIZE_MAX
#  error wrong BUFFER_SIZE
# endif

typedef struct		s_list
{
	int				fd;
	char			*data;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
int					handle_error(t_list	**list);
int					handle_eof(t_list **list, int fd);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*data_add(char *data, const char *buf, int actl_buf_len);
char				*ft_strdup(const char *s1);
char				*cut_first_line(char **data);

#endif
