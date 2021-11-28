/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:18:41 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/03 15:29:38 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	music_load(t_prime *prime)
{
	prime->theme = Mix_LoadWAV("bonus/Main_Theme.wav");
	prime->shag = Mix_LoadWAV("bonus/shag.wav");
	prime->monetka = Mix_LoadWAV("bonus/Monetka.wav");
	Mix_PlayChannel(-1, prime->theme, 0);
}

void	save_check(t_prime *prime, char *argv)
{
	if (argv && !(ft_strncmp(argv, "--save", 6)))
	{
		write_bmp(prime);
		exit(0);
	}
}
