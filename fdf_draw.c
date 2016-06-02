/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 07:53:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/02 08:44:37 by daviwel          ###   ########.fr       */
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

void		ft_init_map(t_mapinfo *map)
{	
	t_mapinfo mapcpy;

	//rotate_x(45, &mapcpy);
	map->rot_x = 45;
	map->rot_y = 0;
	map->rot_z = 0;
	//scale_points(map, map->scale_x, map->scale_y);
	mapcpy = *map;
	mapcpy.points = ft_mapcopy(map);
	to_iso(&mapcpy);
	rotate_x(45, &mapcpy);
	ft_centremap(&mapcpy);
	ft_draw_map(mapcpy);
}
