/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:39:36 by Jraye             #+#    #+#             */
/*   Updated: 2020/11/13 17:55:57 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	set_i(char const *s1, char const *set)
{
	size_t		i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

static size_t	set_j(char const *s1, size_t i, char const *set)
{
	size_t		j;

	j = ft_strlen(s1);
	while (j > i)
	{
		if (!ft_strchr(set, s1[j]))
			break ;
		j--;
	}
	j++;
	return (j);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*s2;
	size_t		i;
	size_t		j;
	size_t		k;

	if (!s1 || !set)
		return (NULL);
	i = set_i(s1, set);
	k = 0;
	j = set_j(s1, i, set);
	s2 = (char*)malloc(sizeof(*s2) * (j - i + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < j)
	{
		s2[k] = s1[i];
		k++;
		i++;
	}
	s2[k] = '\0';
	return (s2);
}
