/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:37:19 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/03 14:41:16 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_lines(t_prime *prime, int x, int n, int h)
{
	int pos;
	int color;

	while (h < prime->begin_point)
	{
		pixel_put(prime->win, x, h, prime->parse->c_rgb);
		h++;
	}
	while (prime->begin_point < prime->end_point)
	{
		prime->tex_y = (int)prime->t_pos & (prime->parse->img_h[n] - 1);
		prime->t_pos += prime->t_step;
		pos = (prime->tex_y * prime->parse->line_length + prime->tex_x
		* (prime->parse->bits_per_pixel / 8));
		color = *(unsigned int *)(prime->parse->addr[n] + pos);
		pixel_put(prime->win, x, prime->begin_point, color);
		prime->begin_point++;
	}
	h = prime->end_point;
	while (h < prime->s_h)
	{
		pixel_put(prime->win, x, h, prime->parse->f_rgb);
		h++;
	}
}

void	print_lines(t_prime *prime, int x)
{
	int n;

	n = 0;
	if (prime->side == 0 && prime->ray_dir_x < 0)
		n = 3;
	if (prime->side == 0 && prime->ray_dir_x > 0)
		n = 1;
	if (prime->side == 1 && prime->ray_dir_y < 0)
		n = 2;
	if (prime->side == 0)
		prime->wall_x = prime->plr_pos_y + prime->wall_dist * prime->ray_dir_y;
	else
		prime->wall_x = prime->plr_pos_x + prime->wall_dist * prime->ray_dir_x;
	prime->wall_x -= floor((prime->wall_x));
	prime->tex_x = (int)(prime->wall_x * (double)(prime->parse->img_w[n]));
	if (prime->side == 0 && prime->ray_dir_x > 0)
		prime->tex_x = prime->parse->img_w[n] - prime->tex_x - 1;
	if (prime->side == 1 && prime->ray_dir_y < 0)
		prime->tex_x = prime->parse->img_w[n] - prime->tex_x - 1;
	prime->t_step = 1.0 * prime->parse->img_h[n] / prime->line_h;
	prime->t_pos = (prime->begin_point - prime->s_h / 2
	+ prime->line_h / 2) * prime->t_step;
	draw_lines(prime, x, n, 0);
	prime->buf_z[x] = prime->wall_dist;
}
