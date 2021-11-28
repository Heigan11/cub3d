/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:27:55 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/07 19:30:12 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_dist(t_prime *prime)
{
	int		i;

	i = 0;
	while (i < prime->num_sprites)
	{
		prime->sprite[i].dist = ((prime->plr_pos_x - prime->sprite[i].x)
		* (prime->plr_pos_x - prime->sprite[i].x) +
		(prime->plr_pos_y - prime->sprite[i].y)
		* (prime->plr_pos_y - prime->sprite[i].y));
		i++;
	}
}

void	sprite_sort(t_prime *prime)
{
	int			i;
	int			n;
	int			j;
	t_sprite	tmp;

	n = prime->num_sprites;
	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (prime->sprite[j].dist < prime->sprite[j + 1].dist)
			{
				tmp = prime->sprite[j];
				prime->sprite[j] = prime->sprite[j + 1];
				prime->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	calc_params_s(t_prime *prime, int i)
{
	double	k_matrix;

	prime->s_x = prime->sprite[i].x - prime->plr_pos_x;
	prime->s_y = prime->sprite[i].y - prime->plr_pos_y;
	k_matrix = 1.0 / (prime->win_x * prime->plr_dir_y
	- prime->plr_dir_x * prime->win_y);
	prime->new_x = k_matrix * (prime->plr_dir_y * prime->s_x
	- prime->plr_dir_x * prime->s_y);
	prime->new_y = k_matrix * (-prime->win_y * prime->s_x
	+ prime->win_x * prime->s_y);
	prime->spr_scr_x = (int)((prime->s_w / 2)
	* (1 + prime->new_x / prime->new_y));
	prime->spr_h = (int)(prime->s_h / (prime->new_y));
	prime->draw_b_y = -prime->spr_h / 2 + prime->s_h / 2;
}

void	sprite_print(t_prime *prime)
{
	int		i;

	i = 0;
	set_dist(prime);
	sprite_sort(prime);
	while (i < prime->num_sprites)
	{
		calc_params_s(prime, i);
		if (prime->draw_b_y < 0)
			prime->draw_b_y = 0;
		prime->draw_e_y = prime->spr_h / 2 + prime->s_h / 2;
		if (prime->draw_e_y >= prime->s_h)
			prime->draw_e_y = prime->s_h - 1;
		prime->spr_w = (int)(prime->s_h / (prime->new_y));
		prime->draw_b_x = -prime->spr_w / 2 + prime->spr_scr_x;
		if (prime->draw_b_x < 0)
			prime->draw_b_x = 0;
		prime->draw_e_x = prime->spr_w / 2 + prime->spr_scr_x;
		if (prime->draw_e_x >= prime->s_w)
			prime->draw_e_x = prime->s_w - 1;
		prime->line = prime->draw_b_x;
		sprite_draw(prime, i);
		i++;
	}
}
