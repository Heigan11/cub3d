/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:47:38 by jraye             #+#    #+#             */
/*   Updated: 2020/11/10 14:36:42 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	i = 0;
	j = 0;
	while (i < n)
	{
		if (s3[i] == '\0' || s4[i] == '\0')
			return (s3[i] - s4[i]);
		if (s3[i] < s4[i])
			return (-1);
		if (s3[i] > s4[i])
			return (1);
		i++;
	}
	return (0);
}
