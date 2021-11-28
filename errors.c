/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:26:42 by Jraye             #+#    #+#             */
/*   Updated: 2021/01/30 18:49:45 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_print(char enum_error)
{
	enum_error == BAD_MALLOC ? write(2, "Error: malloc fail\n", 19) : 0;
	enum_error == BAD_FD ? write(2, "Error: bad file\n", 16) : 0;
	enum_error == BAD_MAP ? write(2, "Error: bad map\n", 15) : 0;
	enum_error == DUP_KEY ? write(2, "Error: duplicate params\n", 24) : 0;
	enum_error == BAD_TEX ? write(2, "Error: bad texture\n", 19) : 0;
	enum_error == BAD_COL ? write(2, "Error: bad color\n", 17) : 0;
	enum_error == BAD_KEY ? write(2, "Error: bad key\n", 15) : 0;
	enum_error == BAD_ARGV ? write(2, "Error: bad arguments\n", 21) : 0;
	enum_error == BAD_RES ? write(2, "Error: bad resolution\n", 22) : 0;
	exit(enum_error);
}
