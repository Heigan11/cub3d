/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:55:56 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/07 19:35:30 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	parse_init(t_prime *prime)
{
	prime->s_w = 0;
	prime->s_h = 0;
	prime->parse->buf = 0;
	prime->parse->f_r = 0;
	prime->parse->f_g = 0;
	prime->parse->f_b = 0;
	prime->parse->c_r = 0;
	prime->parse->c_g = 0;
	prime->parse->c_b = 0;
	prime->num_params = 0;
	prime->plr_dir_x = 0;
	prime->plr_dir_y = 0;
	prime->win_x = 0;
	prime->win_y = 0;
	prime->num_sprites = 0;
	prime->tex[8] = "bonus/health2.xpm";
	prime->tex[9] = "bonus/health3.xpm";
}

void	get_params(int fd, char **line, t_prime *prime)
{
	t_list	*first;
	t_list	*temp;
	int		i;

	i = 0;
	first = NULL;
	temp = NULL;
	while (1)
	{
		(get_next_line(fd, line)) == 0 ? error_print(BAD_MAP) : 0;
		if (*line[0] == ' ' || *line[0] == '1')
			break ;
		ft_lstadd_back(&first, ft_lstnew(*line));
	}
	ft_lstadd_back(&first, ft_lstnew(*line));
	temp = first;
	prime->params_size = ft_lstsize(first) - 1;
	prime->params = ft_calloc(ft_lstsize(first), sizeof(char *));
	while (temp)
	{
		prime->params[i] = temp->content;
		temp = temp->next;
		i++;
	}
	free_list(first);
}

void	params_sub_parse(t_prime *prime, int i)
{
	if (prime->params[i][0] == 'S' && prime->params[i][1] == ' ')
		set_tex(prime, i, 4);
	else if (prime->params[i][0] == 'S' && prime->params[i][1] == '1'
			&& prime->params[i][2] == ' ')
		set_tex(prime, i, 5);
	else if (prime->params[i][0] == 'S' && prime->params[i][1] == 'Y'
			&& prime->params[i][2] == ' ')
		set_tex(prime, i, 6);
	else if (prime->params[i][0] == 'T' && prime->params[i][1] == ' ')
		set_tex(prime, i, 7);
	else if (prime->params[i][0] == 'F' && prime->params[i][1] == ' ')
		set_color_f(prime, i);
	else if (prime->params[i][0] == 'C' && prime->params[i][1] == ' ')
		set_color_c(prime, i);
	else if (prime->params[i][0] == '\0')
		i++;
	else
		error_print(BAD_KEY);
}

void	params_parse(t_prime *prime, int i)
{
	parse_init(prime);
	while (i < prime->params_size)
	{
		if (prime->params[i][0] == 'R')
			set_r(prime, i);
		else if (prime->params[i][0] == 'N' && prime->params[i][1] == 'O'
		&& prime->params[i][2] == ' ')
			set_tex(prime, i, 3);
		else if (prime->params[i][0] == 'S' && prime->params[i][1] == 'O'
		&& prime->params[i][2] == ' ')
			set_tex(prime, i, 1);
		else if (prime->params[i][0] == 'W' && prime->params[i][1] == 'E'
		&& prime->params[i][2] == ' ')
			set_tex(prime, i, 0);
		else if (prime->params[i][0] == 'E' && prime->params[i][1] == 'A'
		&& prime->params[i][2] == ' ')
			set_tex(prime, i, 2);
		else
			params_sub_parse(prime, i);
		i++;
	}
	key_check(prime);
}

void	make_map(t_prime *prime, char *argv)
{
	int		fd;
	char	*line;
	t_list	*first;
	t_list	*temp;

	first = NULL;
	temp = NULL;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_print(BAD_FD);
	get_params(fd, &line, prime);
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&first, ft_lstnew(line));
	close(fd);
	ft_lstadd_back(&first, ft_lstnew(line));
	temp = first;
	prime->map = ft_calloc(ft_lstsize(first) + 2, sizeof(char *));
	prime->map[0] = prime->params[prime->params_size];
	set_map(prime, temp);
	free_list(first);
	params_parse(prime, 0);
	map_check(prime);
	set_obj(prime, 0, 0);
}
