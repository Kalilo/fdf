/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:44:49 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/01 08:17:48 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		get_point(int x, int y, t_mapinfo map)
{
	int	pt;
	int	per_line;
	int	i;

	pt = 0;
	i = 0;
	per_line = map.points_num / map.lines;
	while (i < y)
	{
		pt += per_line;
		i++;
	}
	pt += per_line + x;
	return (map.points[x][y]);
}

t_point 	new_point(int x, int y, int z)
{
	t_point	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

void		translate_point(int x, int y, int z, t_mapinfo *map)
{
	int	i;
	int	k;

	i = 0;
	while (i < map->lines)
	{
		k = 0;
		while (k < map->width)
		{
			map->points[i][k].x += x;
			map->points[i][k].z += z;
			map->points[i][k].y += y;
			k++;
		}
		i++;
	}
}

void	to_iso(t_mapinfo *map)
{
	int	i;
	int	k;
	int	p1;
	int	p2;

	i = 0;
	while (i < map->lines)
	{
		k = 0;
		while (k < map->width)
		{
			p1 = map->points[i][k].x;
			p2 = map->points[i][k].z;
			map->points[i][k].x = (p1 - p2) * map->scale_x + map->points[i][k].y;
			map->points[i][k].z = (p1 + p2) * map->scale_x + map->points[i][k].y;
			map->points[i][k].y *= map->scale_y;
			k++;
		}
		i++;
	}
}

void		scale_points(t_mapinfo *map, int scale_x, int scale_y)
{
	int i;
	int	k;

	i = 0;
	while (i < map->lines)
	{
		k = 0;
		while (k < map->width)
		{
			map->points[i][k].x *= scale_x;
			map->points[i][k].y *= scale_y;
			map->points[i][k].z *= scale_x;
			k++;
		}
		i++;
	}
}
