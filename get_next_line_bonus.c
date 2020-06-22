/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:28:44 by kdustin           #+#    #+#             */
/*   Updated: 2020/06/22 03:13:29 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*add_elem(t_list *list_head, int fd)
{
	t_list	*new_elem;
	t_list	*head;

	if (!(new_elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_elem->fd = fd;
	new_elem->data = NULL;
	new_elem->next = NULL;
	if (list_head == NULL)
		return (new_elem);
	head = list_head;
	while (list_head->next != NULL)
		list_head = list_head->next;
	list_head->next = new_elem;
	return (head);
}

t_list	*find_by_fd(t_list *list_head, int fd)
{
	while (list_head && list_head->fd != fd)
	{
		list_head = list_head->next;
	}
	return (list_head);
}

int		handle_error(t_list **list)
{
	t_list	*temp;
	t_list	*prev;

	while (*list != NULL)
	{
		prev = NULL;
		temp = *list;
		while (temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		free(temp->data);
		free(temp);
		if (prev)
			prev->next = NULL;
		*list = NULL;
	}
	return (-1);
}

int		handle_eof(t_list **list, int fd)
{
	t_list	*head;
	t_list	*prev;

	head = *list;
	prev = NULL;
	while ((*list) != NULL && (*list)->fd != fd)
	{
		prev = *list;
		*list = (*list)->next;
	}
	if (*list != NULL)
	{
		if (prev)
			prev->next = (*list)->next;
		free((*list)->data);
		free(*list);
		*list = NULL;
	}
	if (prev)
		*list = head;
	else
		*list = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE];
	static t_list	*list;
	int				rd;
	t_list			*cur;

	if (!(cur = find_by_fd(list, fd)))
	{
		if (!(list = add_elem(list, fd)))
			return (handle_error(&list));
		cur = find_by_fd(list, fd);
	}
	buf[0] = '\0';
	rd = 1;
	while (!ft_strchr(cur->data, '\n') && (rd = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (!(cur->data = data_add(cur->data, buf, rd)))
			return (handle_error(&list));
	}
	if (rd < 0)
		return (handle_error(&list));
	if (!(*line = cut_first_line(&cur->data)))
		return (handle_error(&list));
	if (rd == 0)
		return (handle_eof(&list, fd));
	return (1);
}
