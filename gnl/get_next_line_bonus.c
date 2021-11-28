/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:41:45 by Jraye             #+#    #+#             */
/*   Updated: 2020/11/27 19:46:30 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	free_gnl(char **retry, char **buf, int res)
{
	if (retry)
		free(*retry);
	if (buf)
		free(*buf);
	return (res);
}

int	read_cycle(int fd, char **line, char **retry)
{
	char	*buf;
	int		count;
	char	*tmp;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (free_gnl(retry, NULL, -1));
	while (!ft_strchr(*retry, '\n'))
	{
		if ((count = read(fd, buf, BUFFER_SIZE)) < 0)
			return (free_gnl(NULL, &buf, -1));
		buf[count] = '\0';
		tmp = ft_strjoin(*retry, buf);
		free(*retry);
		*retry = tmp;
		if (count == 0)
		{
			*line = ft_strdup(*retry);
			free_gnl(retry, &buf, 0);
			*retry = NULL;
			return (0);
		}
	}
	return (free_gnl(NULL, &buf, 1));
}

int	get_line(int fd, char **line, char **retry)
{
	char	*tmp;

	if (BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!*retry)
	{
		if (!(*retry = (char*)malloc(sizeof(char) * 1)))
			return (-1);
		*retry[0] = '\0';
	}
	*line = NULL;
	if ((read_cycle(fd, line, retry)) == 0)
		return (0);
	if ((read_cycle(fd, line, retry)) == -1)
		return (-1);
	*ft_strchr(*retry, '\n') = '\0';
	if (!(*line = ft_strdup(*retry)))
		return (free_gnl(retry, NULL, -1));
	if (!(tmp = ft_strdup(ft_strchr(*retry, '\0') + 1)))
		return (free_gnl(retry, NULL, -1));
	free(*retry);
	*retry = tmp;
	return (1);
}

int	delone_gnl(t_list **first, int fd, int res)
{
	t_list	*temp;
	t_list	*down;

	temp = *first;
	if (temp->fd == fd)
	{
		*first = temp->next;
		free(temp);
		return (res);
	}
	while (temp->fd != fd)
	{
		down = temp;
		temp = temp->next;
	}
	down->next = temp->next;
	free(temp);
	return (res);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*first;
	t_list			*temp;
	int				res;

	if (!first)
		if (!(first = ft_lstnew_gnl(fd)))
			return (-1);
	temp = first;
	while (temp->fd != fd)
	{
		if (!temp->next)
			temp->next = ft_lstnew_gnl(fd);
		temp = temp->next;
	}
	res = get_line(temp->fd, line, &temp->retry);
	if (res == 0)
		return (delone_gnl(&first, fd, 0));
	if (res == -1)
		return (delone_gnl(&first, fd, -1));
	return (res);
}
