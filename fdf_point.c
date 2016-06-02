/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:56:45 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/02 15:56:48 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		new_point(int x, int y, int z)
{
	t_point	new;

	new.x = x;
	new.y = y;
	new.z = z;
	if (new.y > 0)
		new.col = 1;
	else
		new.col = 0;
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
