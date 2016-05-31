/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_movemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 09:11:32 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/31 09:48:23 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_findcentre(t_mapinfo map)
{
	return (map.points[map.scale_x / 2][map.scale_y / 2]);
}

void	ft_centremap(t_mapinfo *map)
{
	int		offset_x;
	int		offset_y;
	t_point	centre;

	centre = ft_findcentre(*map);
	offset_x = centre.x;
	offset_y = centre.z;
	ft_movemap(map, offset_x, offset_y);
}

void	ft_movemap(t_mapinfo *map, int offset_x, int offset_y)
{
	int	i;
	int	k;

	i = 0;
	while (i < map->lines)
	{
		while (k < map->width)
		{
			map->points[i][k].x += offset_x;
			map->points[i][k].z += offset_y;
			k++;
		}
		i++;
	}
}
