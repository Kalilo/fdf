/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 07:53:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/31 17:12:06 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_mapinfo map)
{
	int		u;
	int		v;
	int		col;

	v = 0;
	while (v < map.lines)
	{
		u = 0;
		while (u < map.width)
		{
			col = 0x00FFFFFF;
			if (map.points[v][u].y > 0)
				col = 0x00FF0000;
			if (v < map.lines - 1)
				draw_line(map.points[v][u], map.points[v + 1][u], &map);
			if (u < map.width - 1)
				draw_line(map.points[v][u], map.points[v][u + 1], &map);
			u++;
		}
		v++;
	}
}

/*int	my_key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}*/

void		ft_init_map(t_mapinfo *map)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_X, WIN_Y, "FdF");
	map->mlx = mlx;
	map->win = win;		
	//scale_points(map, map->scale_x, map->scale_y);
	to_iso(map);
	translate_rot(-45, map, &rotate_x);	
	//calc_perspective(300, map);
	//rotate_x(90, &map);
	//rotate_z(1, &map);
	//rotate_y(45, &map);	
	print_cloud(*map);
	ft_centremap(map);
	//ft_draw_map(map);
	//mlx_key_hook(map.win, my_key_funct, 0);
	//mlx_loop(map.mlx);
}
