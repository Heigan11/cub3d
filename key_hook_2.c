/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:25:11 by Jraye             #+#    #+#             */
/*   Updated: 2021/01/31 12:06:15 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hook_key_124(t_prime *prime)
{
	double tmp_dir_x;
	double tmp_plane_x;

	tmp_dir_x = prime->plr_dir_x;
	prime->plr_dir_x = prime->plr_dir_x * cos(-prime->plr_r_speed) -
	prime->plr_dir_y * sin(-prime->plr_r_speed);
	prime->plr_dir_y = tmp_dir_x * sin(-prime->plr_r_speed) +
	prime->plr_dir_y * cos(-prime->plr_r_speed);
	tmp_plane_x = prime->win_x;
	prime->win_x = prime->win_x * cos(-prime->plr_r_speed) -
	prime->win_y * sin(-prime->plr_r_speed);
	prime->win_y = tmp_plane_x * sin(-prime->plr_r_speed) +
	prime->win_y * cos(-prime->plr_r_speed);
}

void	hook_key_123(t_prime *prime)
{
	double tmp_dir_x;
	double tmp_plane_x;

	tmp_dir_x = prime->plr_dir_x;
	prime->plr_dir_x = prime->plr_dir_x * cos(prime->plr_r_speed) -
	prime->plr_dir_y * sin(prime->plr_r_speed);
	prime->plr_dir_y = tmp_dir_x * sin(prime->plr_r_speed) +
	prime->plr_dir_y * cos(prime->plr_r_speed);
	tmp_plane_x = prime->win_x;
	prime->win_x = prime->win_x * cos(prime->plr_r_speed) -
	prime->win_y * sin(prime->plr_r_speed);
	prime->win_y = tmp_plane_x * sin(prime->plr_r_speed) +
	prime->win_y * cos(prime->plr_r_speed);
}
