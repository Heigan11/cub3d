/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_health_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:56:47 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/03 16:28:18 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_draw_sub(t_prime *prime, int i)
{
	int pos;
	int color;
	int y;
	int d;

	y = prime->draw_b_y;
	while (y < prime->draw_e_y)
	{
		d = y * 256 - prime->s_h * 128 + prime->spr_h * 128;
		prime->spr_tex_y = ((d *
	prime->parse->img_h[prime->sprite[i].tex_num]) / prime->spr_h) / 256;
		pos = (prime->spr_tex_y * prime->parse->line_length +
		prime->spr_tex_x * (prime->parse->bits_per_pixel / 8));
		color = *(unsigned int *)
		(prime->parse->addr[prime->sprite[i].tex_num] + pos);
		if ((color & 0x00FFFFFF) != 0)
			pixel_put(prime->win, prime->line, y, color);
		y++;
	}
}

void	sprite_draw(t_prime *prime, int i)
{
	while (prime->line < prime->draw_e_x)
	{
		prime->spr_tex_x = (int)(256 * (prime->line -
		(-prime->spr_w / 2 + prime->spr_scr_x)) *
		prime->parse->img_w[prime->sprite[i].tex_num] / prime->spr_w) / 256;
		if (prime->new_y > 0 && prime->line > 0 && prime->line < prime->s_w
		&& prime->new_y < prime->buf_z[prime->line])
			sprite_draw_sub(prime, i);
		prime->line++;
	}
}
