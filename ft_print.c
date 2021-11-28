/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 13:49:49 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/04 14:55:38 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_params_x(t_prime *prime, int x)
{
	prime->cam_x = 2 * x / (double)prime->s_w - 1;
	prime->ray_dir_x = prime->plr_dir_x + prime->win_x * prime->cam_x;
	prime->ray_dir_y = prime->plr_dir_y + prime->win_y * prime->cam_x;
	prime->map_x = (int)prime->plr_pos_x;
	prime->map_y = (int)prime->plr_pos_y;
	prime->dray_dist_x = fabs(1 / prime->ray_dir_x);
	prime->dray_dist_y = fabs(1 / prime->ray_dir_y);
}

void	check_sign(t_prime *prime)
{
	if (prime->ray_dir_x < 0)
	{
		prime->step_x = -1;
		prime->fray_dist_x = (prime->plr_pos_x - prime->map_x)
	* prime->dray_dist_x;
	}
	else
	{
		prime->step_x = 1;
		prime->fray_dist_x = (prime->map_x + 1.0 - prime->plr_pos_x)
		* prime->dray_dist_x;
	}
	if (prime->ray_dir_y < 0)
	{
		prime->step_y = -1;
		prime->fray_dist_y = (prime->plr_pos_y - prime->map_y)
		* prime->dray_dist_y;
	}
	else
	{
		prime->step_y = 1;
		prime->fray_dist_y = (prime->map_y + 1.0 - prime->plr_pos_y)
		* prime->dray_dist_y;
	}
}

void	check_hit(t_prime *prime, int hit)
{
	while (hit == 0)
	{
		if (prime->fray_dist_x < prime->fray_dist_y)
		{
			prime->fray_dist_x += prime->dray_dist_x;
			prime->map_x += prime->step_x;
			prime->side = 0;
		}
		else
		{
			prime->fray_dist_y += prime->dray_dist_y;
			prime->map_y += prime->step_y;
			prime->side = 1;
		}
		if (prime->map[prime->map_x][prime->map_y] == '1')
			hit = 1;
	}
}

void	check_side_set_points(t_prime *prime)
{
	if (prime->side == 0)
		prime->wall_dist = (prime->map_x - prime->plr_pos_x
		+ (1 - prime->step_x) / 2) / prime->ray_dir_x;
	else
		prime->wall_dist = (prime->map_y - prime->plr_pos_y
		+ (1 - prime->step_y) / 2) / prime->ray_dir_y;
	prime->line_h = (int)(prime->s_h / prime->wall_dist);
	prime->begin_point = -prime->line_h / 2 + prime->s_h / 2;
	if (prime->begin_point < 0)
		prime->begin_point = 0;
	prime->end_point = prime->line_h / 2 + prime->s_h / 2;
	if (prime->end_point >= prime->s_h)
		prime->end_point = prime->s_h - 1;
}

void	ft_print(t_prime *prime)
{
	int hit;
	int x;

	x = 0;
	prime->win->img = mlx_new_image(prime->win->mlx, prime->s_w, prime->s_h);
	prime->win->addr = mlx_get_data_addr(prime->win->img,
	&prime->win->bits_per_pixel, &prime->win->line_length, &prime->win->endian);
	while (x < prime->s_w)
	{
		hit = 0;
		calc_params_x(prime, x);
		check_sign(prime);
		check_hit(prime, hit);
		check_side_set_points(prime);
		print_lines(prime, x);
		x++;
	}
	sprite_print(prime);
	if (prime->save == 0)
	{
		mlx_put_image_to_window(prime->win->mlx,
		prime->win->win, prime->win->img, 0, 0);
		mlx_do_sync(prime->win->mlx);
		mlx_destroy_image(prime->win->mlx, prime->win->img);
	}
}
