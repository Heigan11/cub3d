/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:08:36 by Jraye             #+#    #+#             */
/*   Updated: 2020/11/16 16:30:56 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s1, char c)
{
	size_t		i;
	size_t		count;

	count = 0;
	i = 0;
	if (s1[0] != c && s1[0] != '\0')
		count++;
	while (i < ft_strlen(s1))
	{
		if (s1[i] == c)
		{
			while (s1[i] == c)
				i++;
			if (s1[i] != '\0')
				count++;
		}
		i++;
	}
	return (count);
}

static size_t	next_begin_index(char const *s1, char c, size_t index, size_t i)
{
	if (i == 0 && s1[index - 1] != c)
		return (0);
	if (i == 0)
		index--;
	while (index < ft_strlen(s1))
	{
		if (s1[index] == c)
		{
			while (s1[index] == c)
				index++;
			return (index);
		}
		index++;
	}
	return (index);
}

static size_t	word_length(char const *s1, char c, size_t index)
{
	size_t	len;

	len = 0;
	while (s1[index] != c && s1[index])
	{
		index++;
		len++;
	}
	return (len);
}

static char		**set_char(char **res, char const *s1, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		index;

	i = 0;
	j = 0;
	index = 0;
	while (i < ft_count(s1, c))
	{
		j = 0;
		index = next_begin_index(s1, c, index + 1, i);
		k = index;
		while (j < word_length(s1, c, index))
		{
			res[i][j] = s1[k];
			j++;
			k++;
		}
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}

char			**ft_split(char const *s, char c)
{
	char		**res;
	size_t		index;
	size_t		i;

	i = 0;
	index = 0;
	res = (char**)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (i < ft_count(s, c))
	{
		index = next_begin_index(s, c, index + 1, i);
		res[i] = (char*)malloc(sizeof(char) *
		(word_length(s, c, index) + 1));
		if (res[i] == NULL)
		{
			while (i-- > 0)
				free(res[i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res = set_char(res, s, c);
	return (res);
}
