/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:53:14 by Jraye             #+#    #+#             */
/*   Updated: 2020/12/22 18:05:19 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct			s_list_gnl
{
	int					fd;
	char				*retry;
	struct s_list_gnl	*next;
}						t_list_gnl;

int						get_next_line(int fd, char **line);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char const *s1, char const *s2);
void					*ft_calloc(size_t count, size_t size);
char					*ft_strchr(const char *s, int c);
size_t					ft_strlen(const char *s);

#endif
