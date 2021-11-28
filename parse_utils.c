/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:37:32 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/07 13:32:27 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **tmp)
{
	int j;

	j = 0;
	while (tmp[j])
	{
		free(tmp[j]);
		j++;
	}
	free(tmp);
}

void	free_list(t_list *first)
{
	while (first)
	{
		free(first);
		first = first->next;
	}
}

void	img_set(t_prime *prime, int n)
{
	if (!(prime->parse->mlx = ft_calloc(5, sizeof(void *))))
		error_print(BAD_MALLOC);
	if (!(prime->parse->img = ft_calloc(5, sizeof(void *))))
		error_print(BAD_MALLOC);
	if (!(prime->parse->addr = ft_calloc(5, sizeof(char *))))
		error_print(BAD_MALLOC);
	if (!(prime->parse->img_w = ft_calloc(5, sizeof(int))))
		error_print(BAD_MALLOC);
	if (!(prime->parse->img_h = ft_calloc(5, sizeof(int))))
		error_print(BAD_MALLOC);
	while (n < 5)
	{
		prime->parse->mlx[n] = mlx_init();
		if (!(prime->parse->img[n] = mlx_xpm_file_to_image(prime->parse->mlx[n],
		prime->tex[n], &prime->parse->img_w[n], &prime->parse->img_h[n])))
			error_print(BAD_TEX);
		if (prime->parse->img_w[n] != 64 || prime->parse->img_h[n] != 64)
			error_print(BAD_TEX);
		prime->parse->addr[n] = mlx_get_data_addr(prime->parse->img[n],
		&prime->parse->bits_per_pixel, &prime->parse->line_length,
		&prime->parse->endian);
		n++;
	}
}

void	check_res_num(char **tmp)
{
	int	i;
	int	j;

	j = 1;
	if (tmp[1][0] == '0' || tmp[2][0] == '0')
		error_print(BAD_RES);
	while (j < 3)
	{
		i = 0;
		while (tmp[j][i])
		{
			if (!ft_isdigit(tmp[j][i]))
				error_print(BAD_RES);
			i++;
		}
		j++;
	}
}
