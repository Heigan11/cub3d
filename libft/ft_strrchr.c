/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:48:39 by jraye             #+#    #+#             */
/*   Updated: 2020/11/07 11:45:46 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;
	char	*s1;

	s1 = (char*)s;
	length = ft_strlen(s);
	while (length >= 0)
	{
		if (s1[length] == c)
			return (&s1[length]);
		length--;
	}
	return (NULL);
}
