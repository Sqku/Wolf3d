/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 16:29:06 by ahua              #+#    #+#             */
/*   Updated: 2015/04/02 16:31:26 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include "libft/libft.h"

# define WIN_HEIGHT 600
# define WIN_WIDTH 800
# define MAPWIDTH 24
# define MAPHEIGHT 24

typedef struct		s_stuff
{
	int line_height;
	int draw_start;
	int draw_end;
	int y;
}					t_stuff;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_img
{
	int				bpp;
	int				size_line;
	void			*img;
	int				endian;
	char			*data;

	int				lx;
	int				ly;
	int				type;
	int				format;
	int				color;

}					t_img;

typedef struct		s_self
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	double			dt;
	double			old_time;
	int				side;
}					t_self;

typedef struct		s_all
{
	t_env			e;
	t_img			img;
	t_self			self;
	int				re;
	char			map[MAPWIDTH][MAPHEIGHT];
}					t_all;

typedef unsigned char	t_byte;

typedef struct		s_color
{
	t_byte r;
	t_byte g;
	t_byte b;
}					t_color;

int					loop_hook(t_all *all);
int					expose_hook(t_all *all);
int					key_hook(int keycode, t_all *all);
void				ft_put_pixel(t_img *img, int x, int y);
void				ft_init(t_all *all);
void				init_map(t_all *all);
int					key(int keycode, t_all *all);
void				up(t_all *all);
void				down(t_all *all);
void				right(t_all *all);
void				left(t_all *all);
void				step(t_all *all);
void				search_wall(t_all *all, int hit);
void				init_pos(t_all *all, int x);
void				camera(t_all *all);
void				draw(t_all *all, int x);
void				color(t_all *all, t_stuff *stuff, int x);
#endif
