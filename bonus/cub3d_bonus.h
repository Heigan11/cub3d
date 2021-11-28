/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:15:21 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/07 13:34:16 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include "SDL.h"
# include "SDL_mixer.h"
# include <math.h>

enum			e_errors
{
	BAD_MALLOC = 1,
	BAD_FD,
	BAD_MAP,
	DUP_KEY,
	BAD_TEX,
	BAD_COL,
	BAD_KEY,
	BAD_ARGV,
	BAD_RES
};

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_win;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
	int			tex_num;
}				t_sprite;

typedef struct	s_parse
{
	char		*buf;
	int			*img_w;
	int			*img_h;
	int			f_r;
	int			f_g;
	int			f_b;
	int			f_rgb;
	int			c_r;
	int			c_g;
	int			c_b;
	int			c_rgb;
	void		**mlx;
	void		**img;
	char		**addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_parse;

typedef struct	s_prime
{
	t_win		*win;
	t_parse		*parse;
	char		**map;
	char		**tex;
	char		**params;
	int			params_size;
	t_sprite	*sprite;
	double		*buf_z;
	int			health;
	int			s_w;
	int			s_h;
	int			num_sprites;
	double		plr_pos_x;
	double		plr_pos_y;
	double		plr_dir_x;
	double		plr_dir_y;
	double		plr_m_speed;
	double		plr_r_speed;
	double		win_x;
	double		win_y;
	int			map_x;
	int			map_y;
	double		fray_dist_x;
	double		fray_dist_y;
	double		dray_dist_x;
	double		dray_dist_y;
	double		t_step;
	double		t_pos;
	double		s_x;
	double		s_y;
	int			spr_h;
	int			spr_w;
	int			spr_scr_x;
	int			draw_b_y;
	int			draw_e_y;
	int			draw_b_x;
	int			draw_e_x;
	int			line;
	int			spr_tex_x;
	int			spr_tex_y;
	int			step_x;
	int			step_y;
	double		new_x;
	double		new_y;
	int			begin_point;
	int			end_point;
	int			side;
	int			tex_x;
	int			tex_y;
	int			line_h;
	double		wall_x;
	double		wall_dist;
	double		ray_dir_y;
	double		ray_dir_x;
	double		cam_x;
	char		next_step;
	int			mouse_x;
	int			bf_size;
	int			num_params;
	int			map_size;
	int			save;
	void		*theme;
	void		*shag;
	void		*monetka;
	int			set;
	int			i;
	int			j;
	int			k;
}				t_prime;

void			make_map(t_prime *prime, char *argv);
void			map_parse(int fd, char **line, t_prime *prime);
void			write_bmp (t_prime *prime);
void			error_print(char enum_error);
void			check_argv(int argc, char **argv, t_prime *prime);
void			check_color(t_prime *prime);
void			parse_buf(t_prime *prime);
void			check_res(t_prime *prime);
void			key_check(t_prime *prime);
void			trap_set(t_prime *prime);
void			map_check(t_prime *prime);
void			free_split(char **tmp);
void			free_list(t_list *first);
void			set_r(t_prime *prime, int i);
void			set_tex(t_prime *prime, int i, int tex_num);
void			set_color_f(t_prime *prime, int i);
void			set_color_c(t_prime *prime, int i);
void			set_map(t_prime *prime, t_list *temp);
void			set_plr_x(t_prime *prime, double x, double y);
void			set_plr_y(t_prime *prime, double x, double y);
void			set_obj(t_prime *prime, int i, int j);
void			set_sprite(t_prime *prime, int i, int j, int k);
void			free_split(char **tmp);
void			free_list(t_list *first);
int				key_hook(int keycode, t_prime *prime);
void			hook_key_13(t_prime *prime);
void			hook_key_1(t_prime *prime);
void			hook_key_2(t_prime *prime);
void			hook_key_0(t_prime *prime);
void			hook_key_124(t_prime *prime);
void			hook_key_123(t_prime *prime);
void			ft_print(t_prime *prime, int x);
int				exit_esc(void);
void			main_init(t_prime *prime);
void			music_load(t_prime *prime);
void			save_check(t_prime *prime, char *argv);
int				motion_event(int x, int y, t_prime *prime);
void			turn_right(t_prime *prime, double plr_r_speed);
void			turn_left(t_prime *prime, double plr_r_speed);
void			trap_set(t_prime *prime);
void			print_lines(t_prime *prime, int x);
void			sprite_print(t_prime *prime);
void			sprite_draw(t_prime *prime, int i);
void			sprite_sort(t_prime *prime);
void			sprite_draw(t_prime *prime, int i);
void			pixel_put(t_win *win, int x, int y, int color);
void			health_print(t_prime *prime, int x, int y);
void			img_set(t_prime *prime, int n);
void			check_col(char **tmp);
void			check_res_num(char **tmp);

#endif
