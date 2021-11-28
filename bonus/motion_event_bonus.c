/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_event_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:27:48 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/04 15:39:40 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	turn_right(t_prime *prime, double plr_r_speed)
{
	double tmp_dir_x;
	double tmp_plane_x;

	tmp_dir_x = prime->plr_dir_x;
	prime->plr_dir_x = prime->plr_dir_x * cos(-plr_r_speed)
	- prime->plr_dir_y * sin(-plr_r_speed);
	prime->plr_dir_y = tmp_dir_x * sin(-plr_r_speed)
	+ prime->plr_dir_y * cos(-plr_r_speed);
	tmp_plane_x = prime->win_x;
	prime->win_x = prime->win_x * cos(-plr_r_speed)
	- prime->win_y * sin(-plr_r_speed);
	prime->win_y = tmp_plane_x * sin(-plr_r_speed)
	+ prime->win_y * cos(-plr_r_speed);
}

void	turn_left(t_prime *prime, double plr_r_speed)
{
	double tmp_dir_x;
	double tmp_plane_x;

	tmp_dir_x = prime->plr_dir_x;
	prime->plr_dir_x = prime->plr_dir_x * cos(plr_r_speed)
	- prime->plr_dir_y * sin(plr_r_speed);
	prime->plr_dir_y = tmp_dir_x * sin(plr_r_speed)
	+ prime->plr_dir_y * cos(plr_r_speed);
	tmp_plane_x = prime->win_x;
	prime->win_x = prime->win_x * cos(plr_r_speed)
	- prime->win_y * sin(plr_r_speed);
	prime->win_y = tmp_plane_x * sin(plr_r_speed)
	+ prime->win_y * cos(plr_r_speed);
}

int		motion_event(int x, int y, t_prime *prime)
{
	double plr_r_speed;

	y = 0;
	plr_r_speed = 0.08;
	if (x > 3)
		turn_right(prime, plr_r_speed);
	if (x < -3)
		turn_left(prime, plr_r_speed);
	ft_print(prime, 0);
	mlx_mouse_move(prime->win->win, 0, 0);
	return (x);
}
