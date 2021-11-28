/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:33:40 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/07 17:31:48 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_plr_x(t_prime *prime, double x, double y)
{
	prime->plr_dir_x = x;
	prime->win_y = y;
}

void	set_plr_y(t_prime *prime, double x, double y)
{
	prime->plr_dir_y = x;
	prime->win_x = y;
}

void	set_obj(t_prime *prime, int i, int j)
{
	while (prime->map[i])
	{
		j = 0;
		while (prime->map[i][j])
		{
			if ((prime->map[i][j] == 'N' || prime->map[i][j] == 'S' ||
			prime->map[i][j] == 'W' || prime->map[i][j] == 'E'))
			{
				prime->plr_pos_x = i + 0.5;
				prime->plr_pos_y = j + 0.5;
				prime->map[i][j] == 'N' ? set_plr_x(prime, -1.001, 0.6) : 0;
				prime->map[i][j] == 'S' ? set_plr_x(prime, 1.001, -0.6) : 0;
				prime->map[i][j] == 'E' ? set_plr_y(prime, -1.001, -0.6) : 0;
				prime->map[i][j] == 'W' ? set_plr_y(prime, 1.001, 0.6) : 0;
				prime->map[i][j] = '0';
			}
			if (prime->map[i][j] == '2')
				prime->num_sprites++;
			j++;
		}
		i++;
	}
}

void	set_sprite(t_prime *prime, int i, int j, int k)
{
	while (i < prime->map_size)
	{
		j = 0;
		while (prime->map[i][j])
		{
			if (prime->map[i][j] == '2')
			{
				prime->sprite[k].x = i + 0.5;
				prime->sprite[k].y = j + 0.5;
				prime->sprite[k].tex_num = 4;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	check_col(char **tmp)
{
	int	i;
	int	j;

	j = 0;
	while (j < 3)
	{
		if (ft_strlen(tmp[j]) > 3)
			error_print(BAD_COL);
		i = 0;
		while (tmp[j][i])
		{
			if (!ft_isdigit(tmp[j][i]))
				error_print(BAD_COL);
			i++;
		}
		j++;
	}
}
