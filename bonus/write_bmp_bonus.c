/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:57:46 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/03 19:07:46 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	create_bmf_header(int fd, t_prime *prime)
{
	int				i;
	unsigned char	bmf_header[14];

	i = 0;
	ft_bzero(bmf_header, 14);
	bmf_header[0] = 'B';
	bmf_header[1] = 'M';
	bmf_header[2] = (unsigned char)(prime->bf_size);
	bmf_header[3] = (unsigned char)(prime->bf_size >> 8);
	bmf_header[4] = (unsigned char)(prime->bf_size >> 16);
	bmf_header[5] = (unsigned char)(prime->bf_size >> 24);
	bmf_header[10] = (unsigned char)(54);
	write(fd, bmf_header, 14);
}

void	create_bmi_header(int fd, t_prime *prime)
{
	int				i;
	unsigned char	bmi_header[40];

	i = 0;
	ft_bzero(bmi_header, 40);
	bmi_header[0] = (unsigned char)(40);
	bmi_header[4] = (unsigned char)(prime->s_w);
	bmi_header[5] = (unsigned char)(prime->s_w >> 8);
	bmi_header[6] = (unsigned char)(prime->s_w >> 16);
	bmi_header[7] = (unsigned char)(prime->s_w >> 24);
	bmi_header[8] = (unsigned char)(prime->s_h);
	bmi_header[9] = (unsigned char)(prime->s_h >> 8);
	bmi_header[10] = (unsigned char)(prime->s_h >> 16);
	bmi_header[11] = (unsigned char)(prime->s_h >> 24);
	bmi_header[12] = (unsigned char)(1);
	bmi_header[14] = (unsigned char)(24);
	write(fd, bmi_header, 40);
}

int		put_rgb(t_prime *prime, int i, int j)
{
	int	rgb;
	int	color;

	color = *(unsigned int *)(prime->win->addr +
	(4 * prime->s_w * (prime->s_h - 1 - i))
	+ 4 * j);
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

int		pixel_data(int fd, t_prime *prime)
{
	int				i;
	int				j;
	int				color;
	unsigned char	bmppad[3];

	i = 0;
	ft_bzero(bmppad, 3);
	while (i < prime->s_h)
	{
		j = 0;
		while (j < prime->s_w)
		{
			color = put_rgb(prime, i, j);
			write(fd, &color, 3);
			write(fd, &bmppad, 0);
			j++;
		}
		i++;
	}
	return (1);
}

void	write_bmp(t_prime *prime)
{
	int	fd;

	prime->bf_size = 54 + (3 * (prime->s_w) * prime->s_h);
	fd = open("image.bmp", O_WRONLY | O_CREAT, S_IREAD | S_IWRITE);
	create_bmf_header(fd, prime);
	create_bmi_header(fd, prime);
	pixel_data(fd, prime);
	close(fd);
}
