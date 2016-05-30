/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 07:53:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/30 09:01:58 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_map(t_mapinfo mapinfo)
{
	int	x;
	int	y;
	int	i;
	int	k;

	y = 0;
	k = 0;
	while (y < mapinfo.lines)
	{
		x = 0;
		while (x < mapinfo.points_num / mapinfo.lines)
		{
			i = 0x00FFFFFF;
			if (mapinfo.points[k].y > 0)
				i = 0x00FF0000;
			mlx_pixel_put(mapinfo.mlx, mapinfo.win, x * 20, y * 20, i);
			x++;
			k++;
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
