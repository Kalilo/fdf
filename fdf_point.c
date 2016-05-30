/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:21:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/30 09:37:40 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Manipulate t_points*/
#include "fdf.h"

t_point	get_point(int x, int y, t_mapinfo map)
{
	int	pt;
	int	per_line;

	pt = 0;
	per_line = point_num / lines;
	pt += per_line + x;
	return (map.points[pt]);	
}

t_point new_point(float x, float y, float z)
{
	t_point	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

/*Will offset coordinates by respective values*/
void	translate_point(float x, float y, float z, t_point *point)
{
	point->x += x;
	point->y += y;
	point->z += z;
}

void	scale_cloud(t_point *point, float scale_f, int points)
{
	int i;

	i = 0;
	while (i < points)
	{
		point[i].x *= scale_f;
		point[i].y *= scale_f;
		point[i].z *= scale_f;
		i++;
	}
}

void	project_mod(t_point *point, int points, float mod)
{
	int	i;

	i = 0;
	while (i < points)
	{
		point[i].x *= mod;
		point[i].y *= mod;
		i++;
	}
}
