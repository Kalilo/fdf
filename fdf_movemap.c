/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_movemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 09:11:32 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/31 16:48:26 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_centremap(t_mapinfo *map)
{
	int	i;
	int	k;
	int	offset_x;
	int	offset_y;

	i = 0;
	offset_x = map->points[map->lines / 2][map->width / 2].x;
	offset_y = map->points[map->lines / 2][map->width / 2].z;
	while (i < map->lines)
	{
		k = 0;
		while (k < map->width)
		{
			map->points[i][k].x -= offset_x;
			map->points[i][k].x += WIN_X / 2;
			map->points[i][k].z -= offset_y;
			map->points[i][k].z += WIN_Y / 2;
			k++;
		}
		i++;
	}
}

void	calc_perspective(int fl, t_mapinfo *map)
{
    int     u;
    int     v;
	float	pers;

     v = 0;
     while (v < map->lines)
     {
         u = 0;
         while (u < map->width)
         {
			pers = fl / (fl + map->points[v][u].y);
            map->points[v][u].z *= pers;
			map->points[v][u].x *= pers;
            u++;
         }
         v++;
     }
 }	
