/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 07:53:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/30 09:52:44 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_drawline(t_point a, t_point b, t_mapinfo mapinfo)
{
	int	x;
	int	y;
	int	to_x;
	int	to_y;

	if (a.x > b.x)
	{
		x = b.x;
		to_x = a.x;
	}
	else
	{
		x = a.x;
		to_x = b.x;
	}
	if (a.z > b.z)
	{
		y = b.z;
		to_y = a.z;
	}
	else
	{
		y = a.z;
		to_y = b.z;
	}
	while (y < to_y && x < to_x)
	{
		mlx_pixel_put(mapinfo.mlx, mapinfo.win, x * 20, y * 20, 0x00FFFFFF);
		x++;
		y++;
	}
}

static void	ft_draw_map(t_mapinfo mapinfo)
{
	int		x;
	int		y;
	t_point	point;
	int		lp;

	y = 0;
	lp = 0;
	while (y < mapinfo.lines)
	{
		x = 0;
		while (x < mapinfo.points_num / mapinfo.lines)
		{
			point = get_point(x, y, mapinfo);
			printf("%f %f %f\n", point.x, point.y, point.z);
			//mlx_pixel_put(mapinfo.mlx, mapinfo.win, x * 20, y * 20, i);
			if (lp == 1)
				ft_drawline(mapinfo.lastpoint, point, mapinfo);
			mapinfo.lastpoint = point;
			x++;
			lp = 1;
		}
		y++;
	}
	mlx_loop(mapinfo.mlx);
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
