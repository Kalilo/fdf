/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 07:53:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/02 15:10:33 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_instruct(t_mapinfo map)
{
	int	col;

	col = 0x00FFFFFF;
	mlx_string_put(map.mlx, map.win, 5, 5, col, "Q and E for y rotation");
	mlx_string_put(map.mlx, map.win, 5, 20, col, "A and D for x rotation");
	mlx_string_put(map.mlx, map.win, 5, 35, col, "W and S for z rotation");
	mlx_string_put(map.mlx, map.win, 5, 50, col,
			"Arrows for scale. R to reset");
}

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
			if (v < map.lines - 1)
				draw_line(map.points[v][u], map.points[v + 1][u], &map);
			if (u < map.width - 1)
				draw_line(map.points[v][u], map.points[v][u + 1], &map);
			u++;
		}
		v++;
	}
	ft_draw_instruct(map);
}

void	ft_init_map(t_mapinfo *map)
{
	t_mapinfo mapcpy;

	map->rot_x = 245;
	map->rot_y = 110;
	map->rot_z = -125;
	mapcpy = *map;
	mapcpy.points = ft_mapcopy(map);
	scale_points(&mapcpy, map->scale_x, map->scale_y);
	rotate_x(map->rot_x, &mapcpy);
	rotate_y(map->rot_y, &mapcpy);
	rotate_z(map->rot_z, &mapcpy);
	ft_centremap(&mapcpy);
	ft_draw_map(mapcpy);
	free_map(mapcpy);
}
