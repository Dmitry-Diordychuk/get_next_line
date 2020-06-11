/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:28:44 by kdustin           #+#    #+#             */
/*   Updated: 2020/06/11 22:54:13 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE];
	char		*new_line;
	static char	*saved;
	int			read_counter;

	buffer[0] = '\0';
	read_counter = 0;
	while (!(new_line = ft_strchr(buffer, '\n')) && read_counter < BUFFER_SIZE)
	{
		read_counter = read(fd, buffer, BUFFER_SIZE);
		if (!(saved = remalloc(saved, buffer, read_counter)))
			return (-1);
	}
	// Заглушка
	*line = saved;
	// Отрезать кусок.
	return (0);
}
