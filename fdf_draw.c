/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 07:53:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/30 16:13:51 by ddu-toit         ###   ########.fr       */
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
			mlx_pixel_put(map.mlx, map.win, map.points[v][u].x * map.scale_x, map.points[v][u].z * map.scale_y, col);
			u++;
		}
		v++;
	}
	mlx_loop(map.mlx);
}

void		ft_init_map(t_mapinfo mapinfo)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_X, WIN_Y, "FdF");
	mapinfo.mlx = mlx;
	mapinfo.win = win;
	ft_draw_map(mapinfo);
}
