/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:13:38 by Jraye             #+#    #+#             */
/*   Updated: 2020/11/13 17:58:03 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	length;
	char			*s1;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	s1 = (char*)malloc(sizeof(*s1) * (length + 1));
	if (s1 == NULL)
		return (NULL);
	while (i < length)
	{
		s1[i] = (*f)(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
