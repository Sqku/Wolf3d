/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 16:01:43 by ahua              #+#    #+#             */
/*   Updated: 2015/04/02 16:18:01 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	step(t_all *all)
{
	if (all->self.ray_dir_x < 0)
	{
		all->self.step_x = -1;
		all->self.side_dist_x = (all->self.ray_pos_x - all->self.map_x) *
			all->self.delta_dist_x;
	}
	else
	{
		all->self.step_x = 1;
		all->self.side_dist_x = (all->self.map_x + 1.0 - all->self.ray_pos_x) *
			all->self.delta_dist_x;
	}
	if (all->self.ray_dir_y < 0)
	{
		all->self.step_y = -1;
		all->self.side_dist_y = (all->self.ray_pos_y - all->self.map_y) *
			all->self.delta_dist_y;
	}
	else
	{
		all->self.step_y = 1;
		all->self.side_dist_y = (all->self.map_y + 1.0 - all->self.ray_pos_y) *
			all->self.delta_dist_y;
	}
}

void	search_wall(t_all *all, int hit)
{
	while (hit == 0)
	{
		if (all->self.side_dist_x < all->self.side_dist_y)
		{
			all->self.side_dist_x += all->self.delta_dist_x;
			all->self.map_x += all->self.step_x;
			all->self.side = (all->self.step_x < 0 ? 0 : 2);
		}
		else
		{
			all->self.side_dist_y += all->self.delta_dist_y;
			all->self.map_y += all->self.step_y;
			all->self.side = (all->self.step_y > 0 ? 1 : 3);
		}
		if (all->map[all->self.map_x][all->self.map_y] > 0)
			hit = 1;
	}
}

void	init_pos(t_all *all, int x)
{
	all->self.camera_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
	all->self.ray_pos_x = all->self.pos_x;
	all->self.ray_pos_y = all->self.pos_y;
	all->self.ray_dir_x =
		all->self.dir_x + all->self.plane_x * all->self.camera_x;
	all->self.ray_dir_y =
		all->self.dir_y + all->self.plane_y * all->self.camera_x;
	all->self.map_x = (int)(all->self.ray_pos_x);
	all->self.map_y = (int)(all->self.ray_pos_y);
	all->self.delta_dist_x =
		sqrt(1 + (all->self.ray_dir_y * all->self.ray_dir_y) /
				(all->self.ray_dir_x * all->self.ray_dir_x));
	all->self.delta_dist_y =
		sqrt(1 + (all->self.ray_dir_x * all->self.ray_dir_x) /
				(all->self.ray_dir_y * all->self.ray_dir_y));
}

void	camera(t_all *all)
{
	if (all->self.side == 0 || all->self.side == 2)
		all->self.perp_wall_dist =
			fabs((all->self.map_x - all->self.ray_pos_x +
						(1 - all->self.step_x) / 2) / all->self.ray_dir_x);
	else
		all->self.perp_wall_dist =
			fabs((all->self.map_y - all->self.ray_pos_y +
						(1 - all->self.step_y) / 2) / all->self.ray_dir_y);
}
