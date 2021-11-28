/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:33:39 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/07 18:03:35 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put(t_win *win, int x, int y, int color)
{
	char		*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	arrays_init(t_prime *prime)
{
	if (!(prime->buf_z = ft_calloc(prime->s_w, sizeof(prime->buf_z))))
		error_print(BAD_MALLOC);
	if (!(prime->sprite = ft_calloc(prime->num_sprites, sizeof(t_sprite))))
		error_print(BAD_MALLOC);
}

void	sub_main(t_prime *prime, char **argv)
{
	img_set(prime, 0);
	ft_print(prime);
	save_check(prime, argv[2]);
	mlx_hook(prime->win->win, 2, 1L << 0, key_hook, prime);
	mlx_hook(prime->win->win, 17, 1L << 17, exit_esc, prime);
}

int		main(int argc, char **argv)
{
	t_prime		prime;
	t_win		win;
	t_parse		parse;

	check_argv(argc, argv, &prime);
	main_init(&prime);
	if (!(prime.tex = ft_calloc(5, sizeof(char *))))
		error_print(BAD_MALLOC);
	prime.parse = &parse;
	make_map(&prime, argv[1]);
	arrays_init(&prime);
	set_sprite(&prime, 0, 0, 0);
	win.mlx = mlx_init();
	if (prime.save == 0)
	{
		win.win = mlx_new_window(win.mlx, prime.s_w, prime.s_h, "Cub3D");
	}
	prime.win = &win;
	sub_main(&prime, argv);
	mlx_loop(win.mlx);
}
