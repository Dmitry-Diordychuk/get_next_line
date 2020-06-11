/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:31:58 by kdustin           #+#    #+#             */
/*   Updated: 2020/06/11 22:56:48 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i++;
	}
	if (!c)
		return ((char*)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	if (str == NULL)
		return (0);
	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*remalloc(char *str, const char *buf, int actl_buf_len)
{
	char	*result;
	int		i;
	int		j;

	if (!(result = malloc(sizeof(char) * (ft_strlen(str) + actl_buf_len + 1))))
		return (NULL);
	i = 0;
	while (str != NULL && str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	j = i;
	i = 0;
	while (i < actl_buf_len)
		result[j++] = buf[i++];
	result[j] = '\0';
	free(str);
	return(result);
}
