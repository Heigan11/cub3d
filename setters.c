/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:26:54 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/07 19:56:31 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_r(t_prime *prime, int i)
{
	char **tmp;

	tmp = ft_split(prime->params[i], ' ');
	check_res_num(tmp);
	prime->s_w = ft_atoi(tmp[1]);
	prime->s_h = ft_atoi(tmp[2]);
	if (tmp[3])
		error_print(BAD_RES);
	if (ft_strlen(tmp[1]) > 4)
		prime->s_w = 2560;
	if (ft_strlen(tmp[2]) > 4)
		prime->s_h = 1440;
	free_split(tmp);
	check_res(prime);
	prime->num_params++;
}

void	set_tex(t_prime *prime, int i, int tex_num)
{
	char **tmp;

	tmp = ft_split(prime->params[i], ' ');
	prime->tex[tex_num] = ft_strdup(tmp[1]);
	if (tmp[2])
		error_print(BAD_TEX);
	free_split(tmp);
	prime->num_params++;
}

void	set_color_f(t_prime *prime, int i)
{
	char **tmp;

	prime->parse->buf = prime->params[i] + 1;
	parse_buf(prime);
	tmp = ft_split(prime->parse->buf, ',');
	check_col(tmp);
	prime->parse->f_r = ft_atoi(tmp[0]);
	prime->parse->f_g = ft_atoi(tmp[1]);
	prime->parse->f_b = ft_atoi(tmp[2]);
	free_split(tmp);
	check_color(prime);
	prime->parse->f_rgb = prime->parse->f_r * (256 * 256) +
	prime->parse->f_g * 256 + prime->parse->f_b;
	prime->num_params++;
}

void	set_color_c(t_prime *prime, int i)
{
	char **tmp;

	prime->parse->buf = prime->params[i] + 1;
	parse_buf(prime);
	tmp = ft_split(prime->parse->buf, ',');
	check_col(tmp);
	prime->parse->c_r = ft_atoi(tmp[0]);
	prime->parse->c_g = ft_atoi(tmp[1]);
	prime->parse->c_b = ft_atoi(tmp[2]);
	free_split(tmp);
	check_color(prime);
	prime->parse->c_rgb = prime->parse->c_r * (256 * 256) +
	prime->parse->c_g * 256 + prime->parse->c_b;
	prime->num_params++;
}

void	set_map(t_prime *prime, t_list *temp)
{
	int	i;

	i = 1;
	while (temp)
	{
		prime->map[i] = temp->content;
		temp = temp->next;
		i++;
	}
	prime->map_size = i - 2;
}
