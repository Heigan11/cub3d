/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:51:45 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/04 15:39:16 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		key_hook(int keycode, t_prime *prime)
{
	if (keycode == 13 || keycode == 126)
		hook_key_13(prime);
	if (keycode == 1 || keycode == 125)
		hook_key_1(prime);
	if (keycode == 2)
		hook_key_2(prime);
	if (keycode == 0)
		hook_key_0(prime);
	if (keycode == 124)
		hook_key_124(prime);
	if (keycode == 123)
		hook_key_123(prime);
	keycode == 53 ? exit(0) : 0;
	ft_print(prime, 0);
	return (keycode);
}

void	hook_key_13(t_prime *prime)
{
	Mix_PlayChannel(-1, prime->shag, 0);
	prime->next_step = prime->map
	[(int)(prime->plr_pos_x + prime->plr_dir_x * prime->plr_m_speed)]
	[(int)(prime->plr_pos_y)];
	if (prime->next_step == '0' || prime->next_step == '4' ||
	prime->next_step == '5')
	{
		trap_set(prime);
		prime->plr_pos_x += prime->plr_dir_x * prime->plr_m_speed;
	}
	prime->next_step = prime->map[(int)(prime->plr_pos_x)]
	[(int)(prime->plr_pos_y + prime->plr_dir_y * prime->plr_m_speed)];
	if (prime->next_step == '0' || prime->next_step == '4' ||
	prime->next_step == '5')
	{
		trap_set(prime);
		prime->plr_pos_y += prime->plr_dir_y * prime->plr_m_speed;
	}
}

void	hook_key_1(t_prime *prime)
{
	Mix_PlayChannel(-1, prime->shag, 0);
	prime->next_step = prime->map
	[(int)(prime->plr_pos_x - prime->plr_dir_x * prime->plr_m_speed)]
	[(int)(prime->plr_pos_y)];
	if (prime->next_step == '0' || prime->next_step == '4' ||
	prime->next_step == '5')
	{
		trap_set(prime);
		prime->plr_pos_x -= prime->plr_dir_x * prime->plr_m_speed;
	}
	prime->next_step = prime->map[(int)(prime->plr_pos_x)]
	[(int)(prime->plr_pos_y - prime->plr_dir_y * prime->plr_m_speed)];
	if (prime->next_step == '0' || prime->next_step == '4' ||
	prime->next_step == '5')
	{
		trap_set(prime);
		prime->plr_pos_y -= prime->plr_dir_y * prime->plr_m_speed;
	}
}

void	hook_key_2(t_prime *prime)
{
	Mix_PlayChannel(-1, prime->shag, 0);
	prime->next_step = prime->map
	[(int)(prime->plr_pos_x + prime->win_x * prime->plr_m_speed)]
	[(int)(prime->plr_pos_y)];
	if (prime->next_step == '0' || prime->next_step == '4' ||
	prime->next_step == '5')
	{
		trap_set(prime);
		prime->plr_pos_x += prime->win_x * prime->plr_m_speed;
	}
	prime->next_step = prime->map[(int)(prime->plr_pos_x)]
	[(int)(prime->plr_pos_y + prime->win_y * prime->plr_m_speed)];
	if (prime->next_step == '0' || prime->next_step == '4' ||
	prime->next_step == '5')
	{
		trap_set(prime);
		prime->plr_pos_y += prime->win_y * prime->plr_m_speed;
	}
}

void	hook_key_0(t_prime *prime)
{
	Mix_PlayChannel(-1, prime->shag, 0);
	prime->next_step = prime->map
	[(int)(prime->plr_pos_x - prime->win_x * prime->plr_m_speed)]
	[(int)(prime->plr_pos_y)];
	if (prime->next_step == '0' || prime->next_step == '4' ||
	prime->next_step == '5')
	{
		trap_set(prime);
		prime->plr_pos_x -= prime->win_x * prime->plr_m_speed;
	}
	prime->next_step = prime->map[(int)(prime->plr_pos_x)]
	[(int)(prime->plr_pos_y - prime->win_y * prime->plr_m_speed)];
	if (prime->next_step == '0' || prime->next_step == '4' ||
	prime->next_step == '5')
	{
		trap_set(prime);
		prime->plr_pos_y -= prime->win_y * prime->plr_m_speed;
	}
}
