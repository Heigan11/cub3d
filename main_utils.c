/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:18:41 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/03 15:54:02 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_esc(void)
{
	exit(0);
	return (0);
}

void	main_init(t_prime *prime)
{
	prime->health = 8;
	prime->mouse_x = 0;
	prime->plr_m_speed = 0.5;
	prime->plr_r_speed = 0.1;
}

void	save_check(t_prime *prime, char *argv)
{
	if (argv && !(ft_strncmp(argv, "--save", 6)))
	{
		write_bmp(prime);
		exit(0);
	}
}
