/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 07:53:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/31 08:23:03 by daviwel          ###   ########.fr       */
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
			mlx_pixel_put(map.mlx, map.win, map.points[v][u].x, map.points[v][u].z, col);
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
	scale_points(&map, map.scale_x, map.scale_y);
	ft_draw_map(map);
	//temp1.x = 20;
	//temp1.y = 20;
	//temp1.z = 0;
	//temp2.x = 20;
	//temp2.y = 300;
	//temp2.z = 0;
	//draw_line(temp1, temp2, &mapinfo);
	mlx_loop(map.mlx);
}
