/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:04:38 by jraye             #+#    #+#             */
/*   Updated: 2020/11/09 18:58:44 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_simbols(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' ||
		str[i] == '\n' || str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	i = first_simbols(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res * sign < 0 && sign > 0)
		return (-1);
	if (res * sign > 0 && sign < 0)
		return (0);
	return (res * sign);
}
