/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 16:01:10 by ahua              #+#    #+#             */
/*   Updated: 2015/04/02 16:20:49 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init(t_all *all)
{
	all->re = 1;
	all->self.pos_x = 12.5;
	all->self.pos_y = 12.5;
	all->self.dir_x = -1;
	all->self.dir_y = 0;
	all->self.plane_x = 0;
	all->self.plane_y = 0.66;
	all->self.dt = 0;
	all->self.old_time = 0;
}

int		main(void)
{
	t_all	*all;

	all = (t_all*)malloc(sizeof(t_all));
	all->e.mlx = mlx_init();
	all->e.win = mlx_new_window(all->e.mlx, WIN_WIDTH, WIN_HEIGHT, "Wolf3d");
	ft_init(all);
	init_map(all);
	all->img.img = mlx_new_image(all->e.mlx, WIN_WIDTH, WIN_HEIGHT);
	all->img.data = mlx_get_data_addr(all->img.img, &all->img.bpp,
	&all->img.size_line, &all->img.endian);
	mlx_loop_hook(all->e.mlx, loop_hook, all);
	mlx_hook(all->e.win, 2, (1L << 0), key, all);
	mlx_key_hook(all->e.win, key_hook, all);
	mlx_expose_hook(all->e.win, expose_hook, all);
	mlx_loop(all->e.mlx);
	return (0);
}
