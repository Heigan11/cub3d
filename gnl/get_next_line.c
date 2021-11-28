/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:46:38 by Jraye             #+#    #+#             */
/*   Updated: 2020/11/24 14:36:14 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	get_next_line(int fd, char **line)
{
	static char		*retry = NULL;
	char			*tmp;

	if (BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!retry)
		if (!(retry = ft_calloc(1, sizeof(char))))
			return (-1);
	*line = NULL;
	if ((read_cycle(fd, line, &retry)) == 0)
		return (0);
	if ((read_cycle(fd, line, &retry)) == -1)
		return (-1);
	*ft_strchr(retry, '\n') = '\0';
	if (!(*line = ft_strdup(retry)))
		return (free_gnl(&retry, NULL, -1));
	if (!(tmp = ft_strdup(ft_strchr(retry, '\0') + 1)))
		return (free_gnl(&retry, NULL, -1));
	free(retry);
	retry = tmp;
	return (1);
}
