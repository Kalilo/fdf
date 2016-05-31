/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 07:53:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/31 11:27:59 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_map(t_mapinfo map)
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
			//mlx_pixel_put(map.mlx, map.win, map.points[v][u].x, map.points[v][u].z, col);
			if (v < map.lines - 1)
				draw_line(map.points[v][u], map.points[v + 1][u], &map);
			if (u < map.width - 1)
				draw_line(map.points[v][u], map.points[v][u + 1], &map);
			u++;
		}
		v++;
	}
	mlx_loop(map.mlx);
}

void		ft_init_map(t_mapinfo map)
{
	void	*mlx;
	void	*win;

	t_point	temp1;
	t_point	temp2;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_X, WIN_Y, "FdF");
	map.mlx = mlx;
	map.win = win;	
	to_iso(&map);
	//scale_points(&map, map.scale_x, map.scale_y);
	rotate_x(45, &map);
	//rotate_z(-65, &map);
	ft_centremap(&map);
	//rotate_y(30, &map);
	ft_centremap(&map);
	print_cloud(map);
	ft_draw_map(map);
	//mlx_loop(map.mlx);
}
