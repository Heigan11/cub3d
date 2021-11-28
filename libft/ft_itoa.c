/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:27:54 by Jraye             #+#    #+#             */
/*   Updated: 2020/11/15 19:13:08 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	long	n1;
	long	foo;
	int		i;
	int		sign;

	n1 = n;
	sign = 1;
	i = 1;
	foo = n1;
	if (n1 < 0)
	{
		sign = -1;
		i++;
	}
	foo = foo * sign;
	while (foo / 10 >= 1)
	{
		foo = foo / 10;
		i++;
	}
	return (i);
}

static char	*set(char *s, int i, long foo, long n1)
{
	while (i > foo)
	{
		s[i - 1] = n1 % 10 + 48;
		n1 = n1 / 10;
		i--;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		j;
	long	n1;

	n1 = n;
	j = 0;
	i = len(n);
	s = (char*)malloc(sizeof(*s) * (i + 1));
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n1 = n1 * -1;
		j++;
	}
	s = set(s, i, j, n1);
	s[i] = '\0';
	return (s);
}
