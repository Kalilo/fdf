/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_movemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 09:11:32 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/31 10:23:58 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_findcentre(t_mapinfo map)
{
	return (map.points[map.scale_x / 2][map.scale_y / 2]);
}

void	ft_centremap(t_mapinfo *map)
{
	/*int		offset_x;
	int		offset_y;
	t_point	centre;

	centre = ft_findcentre(*map);
	//printf("Hi");
	//printf("%d %d", centre.x, centre.z);
	offset_x = WIN_X / 2 - centre.x;
	offset_y = WIN_Y / 2 - centre.z;*/
	int	i;
	int	k;

	i = 0;
	while (i < map->lines)
	{
		while (k < map->width)
		{
			map->points[i][k].x += WIN_X / 2;
			map->points[i][k].z += WIN_Y / 2;
			k++;
		}
		i++;
	}
	//ft_movemap(map, offset_x, offset_y);
}
