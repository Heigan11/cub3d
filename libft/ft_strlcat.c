/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:06:52 by jraye             #+#    #+#             */
/*   Updated: 2020/11/10 13:24:04 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t res;

	i = ft_strlen(dst);
	if (dstsize < ft_strlen(dst))
	{
		res = ft_strlen(src) + dstsize;
		return (res);
	}
	res = (i + ft_strlcpy(dst + i, src, dstsize - i));
	return (res);
}
