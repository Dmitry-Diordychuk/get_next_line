/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:31:58 by kdustin           #+#    #+#             */
/*   Updated: 2020/06/15 14:34:18 by kdustin          ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*p;

	len = ft_strlen(s1);
	if (!(p = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*cut_first_line(char **str)
{
	char *result;
	char *new_str;
	char *new_line_symbol;

	new_str = NULL;
	new_line_symbol = ft_strchr(*str, '\n');
	if (new_line_symbol != NULL)
	{
		if (new_line_symbol[1] != '\0')
			if (!(new_str = ft_strdup(new_line_symbol + 1)))
				return (NULL);
		*new_line_symbol = '\0';
		if (!(result = ft_strdup(*str)))
		{
			free(new_str);
			return (NULL);
		}
		*str = new_str;
		free(*str);
		return (result);
	}
	if (!(result = ft_strdup(*str)))
		return (NULL);
	free(*str);
	return (result);
}
