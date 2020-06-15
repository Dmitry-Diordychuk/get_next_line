/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:28:44 by kdustin           #+#    #+#             */
/*   Updated: 2020/06/15 15:17:18 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_return_error(char **str)
{
	free(*str);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE];
	char		*new_line_char;
	static char	*saved;
	int			rd_counter;

	buf[0] = '\0';
	rd_counter = 1;
	new_line_char = NULL;
	while (!(new_line_char = ft_strchr(buf, '\n')) && rd_counter > 0)
	{
		rd_counter = read(fd, buf, BUFFER_SIZE);
		if (!(saved = remalloc(saved, buf, rd_counter)))
			return (free_return_error(&saved));
	}
	if (!(*line = cut_first_line(&saved)))
		return (free_return_error(&saved));
	if (saved == NULL)
		return (0);
	return (1);
}
