/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:57:57 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/07 19:31:02 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_first_last_line(t_prime *prime)
{
	int	i;

	i = 0;
	while (prime->map[0][i])
	{
		if (prime->map[0][i] != ' ' && prime->map[0][i] != '1')
			error_print(BAD_MAP);
		i++;
	}
	i = 0;
	while (prime->map[prime->map_size][i])
	{
		if (prime->map[prime->map_size][i] != ' ' &&
		prime->map[prime->map_size][i] != '1')
			error_print(BAD_MAP);
		i++;
	}
}

void	check_plr_symbol(t_prime *prime)
{
	int	i;
	int	j;

	i = 0;
	prime->set = 0;
	while (prime->map[i])
	{
		j = 0;
		while (prime->map[i][j])
		{
			if ((prime->map[i][j] == 'N' || prime->map[i][j] == 'S' ||
			prime->map[i][j] == 'W' || prime->map[i][j] == 'E'))
				prime->set++;
			if ((prime->map[i][j] != 'N' && prime->map[i][j] != 'S' &&
			prime->map[i][j] != 'W' && prime->map[i][j] != 'E' &&
			prime->map[i][j] != ' ' && prime->map[i][j] != '0' &&
			prime->map[i][j] != '1' && prime->map[i][j] != '2' &&
			prime->map[i][j] != '3' && prime->map[i][j] != '4' &&
			prime->map[i][j] != '5'))
				error_print(BAD_MAP);
			j++;
		}
		i++;
	}
	prime->set != 1 ? error_print(BAD_MAP) : 0;
}

void	check_zero(t_prime *prime)
{
	int	i;
	int	j;

	i = 1;
	while (i < (prime->map_size + 1))
	{
		j = 0;
		while (prime->map[i][j])
		{
			if (prime->map[i][j] == '0' || prime->map[i][j] == 'N' ||
			prime->map[i][j] == 'S' || prime->map[i][j] == 'W' ||
			prime->map[i][j] == 'E' || prime->map[i][j] == '2' ||
prime->map[i][j] == '3' || prime->map[i][j] == '4' || prime->map[i][j] == '5')
				if ((prime->map[i - 1][j] == ' ' ||
				prime->map[i - 1][j] == '\0') ||
				(prime->map[i][j - 1] == ' ' || prime->map[i][j - 1] == '\0') ||
				(prime->map[i][j + 1] == ' ' || prime->map[i][j + 1] == '\0') ||
				(prime->map[i + 1][j] == ' ' || prime->map[i + 1][j] == '\0'))
					error_print(BAD_MAP);
			j++;
		}
		if (prime->map[i][0] != ' ' && prime->map[i][0] != '1')
			error_print(BAD_MAP);
		i++;
	}
}

void	map_check(t_prime *prime)
{
	check_first_last_line(prime);
	check_plr_symbol(prime);
	check_zero(prime);
}
