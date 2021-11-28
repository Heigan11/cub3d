/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trap_set_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:39:16 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/03 14:41:42 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	trap_set_sub(t_prime *prime)
{
	if (prime->map[(int)(prime->plr_pos_x)]
	[(int)(prime->plr_pos_y - prime->plr_dir_y * prime->plr_m_speed)] == '5')
		prime->map[(int)(prime->plr_pos_x)]
		[(int)(prime->plr_pos_y - prime->plr_dir_y * prime->plr_m_speed)] = '0';
	if (prime->map
	[(int)(prime->plr_pos_x + prime->win_x * prime->plr_m_speed)]
	[(int)(prime->plr_pos_y)] == '5')
		prime->map
		[(int)(prime->plr_pos_x + prime->win_x * prime->plr_m_speed)]
		[(int)(prime->plr_pos_y)] = '0';
	if (prime->map[(int)(prime->plr_pos_x)]
	[(int)(prime->plr_pos_y + prime->win_y * prime->plr_m_speed)] == '5')
		prime->map[(int)(prime->plr_pos_x)]
		[(int)(prime->plr_pos_y + prime->win_y * prime->plr_m_speed)] = '0';
	if (prime->map
	[(int)(prime->plr_pos_x - prime->win_x * prime->plr_m_speed)]
	[(int)(prime->plr_pos_y)] == '5')
		prime->map
		[(int)(prime->plr_pos_x - prime->win_x * prime->plr_m_speed)]
		[(int)(prime->plr_pos_y)] = '0';
	if (prime->map[(int)(prime->plr_pos_x)]
	[(int)(prime->plr_pos_y - prime->win_y * prime->plr_m_speed)] == '5')
		prime->map[(int)(prime->plr_pos_x)]
		[(int)(prime->plr_pos_y - prime->win_y * prime->plr_m_speed)] = '0';
}

void	trap_set(t_prime *prime)
{
	if (prime->next_step == '5')
	{
		if (prime->map
		[(int)(prime->plr_pos_x + prime->plr_dir_x * prime->plr_m_speed)]
		[(int)(prime->plr_pos_y)] == '5')
			prime->map
			[(int)(prime->plr_pos_x + prime->plr_dir_x * prime->plr_m_speed)]
			[(int)(prime->plr_pos_y)] = '0';
		if (prime->map[(int)(prime->plr_pos_x)]
		[(int)(prime->plr_pos_y + prime->plr_dir_y * prime->plr_m_speed)]
		== '5')
			prime->map[(int)(prime->plr_pos_x)][(int)(prime->plr_pos_y
			+ prime->plr_dir_y * prime->plr_m_speed)] = '0';
		if (prime->map
		[(int)(prime->plr_pos_x - prime->plr_dir_x * prime->plr_m_speed)]
		[(int)(prime->plr_pos_y)] == '5')
			prime->map
			[(int)(prime->plr_pos_x - prime->plr_dir_x * prime->plr_m_speed)]
			[(int)(prime->plr_pos_y)] = '0';
		trap_set_sub(prime);
		prime->num_sprites--;
		Mix_PlayChannel(-1, prime->monetka, 0);
		set_sprite(prime, 0, 0, 0);
		prime->health = 9;
	}
}
