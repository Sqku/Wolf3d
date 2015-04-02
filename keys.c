/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 16:00:52 by ahua              #+#    #+#             */
/*   Updated: 2015/04/02 16:20:13 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	up(t_all *all)
{
	if (all->map[(int)(all->self.pos_x + all->self.dir_x * 0.08)]
			[(int)(all->self.pos_y)] == 0)
		all->self.pos_x += all->self.dir_x * 0.08;
	if (all->map[(int)(all->self.pos_x)]
			[(int)(all->self.pos_y + all->self.dir_y * 0.08)] == 0)
		all->self.pos_y += all->self.dir_y * 0.08;
	all->re = 1;
}

void	down(t_all *all)
{
	if (all->map[(int)(all->self.pos_x - all->self.dir_x * 0.08)]
			[(int)(all->self.pos_y)] == 0)
		all->self.pos_x -= all->self.dir_x * 0.08;
	if (all->map[(int)(all->self.pos_x)][(int)(all->self.pos_y -
				all->self.dir_y * 0.08)] == 0)
		all->self.pos_y -= all->self.dir_y * 0.08;
	all->re = 1;
}

void	left(t_all *all)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = all->self.dir_x;
	old_plane_x = all->self.plane_x;
	all->self.dir_x = all->self.dir_x * cos(-0.02) -
		all->self.dir_y * sin(-0.02);
	all->self.dir_y = old_dir_x * sin(-0.02) + all->self.dir_y * cos(-0.02);
	all->self.plane_x = all->self.plane_x * cos(-0.02) -
		all->self.plane_y * sin(-0.02);
	all->self.plane_y = old_plane_x * sin(-0.02) +
		all->self.plane_y * cos(-0.02);
	all->re = 1;
}

void	right(t_all *all)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = all->self.dir_x;
	old_plane_x = all->self.plane_x;
	all->self.dir_x = all->self.dir_x * cos(0.02) -
		all->self.dir_y * sin(0.02);
	all->self.dir_y = old_dir_x * sin(0.02) + all->self.dir_y * cos(0.02);
	all->self.plane_x = all->self.plane_x * cos(0.02) -
		all->self.plane_y * sin(0.02);
	all->self.plane_y = old_plane_x * sin(0.02) +
		all->self.plane_y * cos(0.02);
	all->re = 1;
}

int		key(int keycode, t_all *all)
{
	if (keycode == 126)
		up(all);
	if (keycode == 125)
		down(all);
	if (keycode == 124)
		left(all);
	if (keycode == 123)
		right(all);
	return (0);
}
