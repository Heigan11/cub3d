/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:54:35 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/07 19:50:00 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_argv(int argc, char **argv, t_prime *prime)
{
	prime->save = 0;
	if (argc < 2 || argc > 3)
		error_print(BAD_ARGV);
	if (ft_strncmp(argv[1], "map.cub", 7) || ft_strlen(argv[1]) > 7)
		error_print(BAD_ARGV);
	if (argv[2])
	{
		if (ft_strncmp(argv[2], "--save", 6) || ft_strlen(argv[2]) > 6)
			error_print(BAD_ARGV);
		else
			prime->save = 1;
	}
}

void	check_color(t_prime *prime)
{
	if (!(prime->parse->f_r >= 0 && prime->parse->f_r <= 255))
		error_print(BAD_COL);
	if (!(prime->parse->f_g >= 0 && prime->parse->f_g <= 255))
		error_print(BAD_COL);
	if (!(prime->parse->f_b >= 0 && prime->parse->f_b <= 255))
		error_print(BAD_COL);
	if (!(prime->parse->c_r >= 0 && prime->parse->c_r <= 255))
		error_print(BAD_COL);
	if (!(prime->parse->c_g >= 0 && prime->parse->c_g <= 255))
		error_print(BAD_COL);
	if (!(prime->parse->c_b >= 0 && prime->parse->c_b <= 255))
		error_print(BAD_COL);
}

void	parse_buf(t_prime *prime)
{
	int		i;
	char	**tmp;

	i = 0;
	while (prime->parse->buf[i])
	{
		if (prime->parse->buf[i] == ' ')
			prime->parse->buf[i] = ',';
		i++;
	}
	tmp = ft_split(prime->parse->buf, ',');
	if (!tmp[2])
		error_print(BAD_COL);
	if (!tmp[1])
		error_print(BAD_COL);
	if (!tmp[0])
		error_print(BAD_COL);
	if (tmp[3])
		error_print(BAD_COL);
	free_split(tmp);
}

void	check_res(t_prime *prime)
{
	if (!prime->s_w || !prime->s_h)
		error_print(BAD_RES);
	if (prime->s_w > 2560 || prime->s_w < 0)
		prime->s_w = 2560;
	if (prime->s_h > 1440 || prime->s_h < 0)
		prime->s_h = 1440;
	if (prime->s_w < 640 && prime->s_w >= 0)
		prime->s_w = 640;
	if (prime->s_h < 480 && prime->s_h >= 0)
		prime->s_h = 480;
}

void	key_check(t_prime *prime)
{
	if (!prime->s_w || !prime->parse->f_r || !prime->parse->c_r ||
	!prime->tex[0] || !prime->tex[1] || !prime->tex[2] ||
	!prime->tex[3] || !prime->tex[4])
		error_print(BAD_KEY);
	if (prime->num_params < 11)
		error_print(BAD_KEY);
	if (prime->num_params > 11)
		error_print(DUP_KEY);
}
