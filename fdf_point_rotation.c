/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:21:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/31 16:42:46 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Manipulate t_points*/
#include "fdf.h"

t_point	fix_neg(t_mapinfo *map)
{
	t_point	ret;
	int	i;
	int k;

	i = 0;
	k = 0;
	ret = new_point(0 , 0, 0);
 		while (i < map->lines)
		{
			k = 0;
			while (k < map->width)
 			{
				if (map->points[i][k].x < ret.x)
					ret.x = map->points[i][k].x;
				if (map->points[i][k].y < ret.y)
					ret.y = map->points[i][k].y;
				if (map->points[i][k].z < ret.z)
					ret.z = map->points[i][k].z;
 				k++;
			}
			i++;
		}
	translate_point((int)ft_fabs(ret.x), (int)ft_fabs(ret.y), (int)ft_fabs(ret.z), map);
	return (ret);
}

void	translate_rot(float angle, t_mapinfo *map, void (f)(float, t_mapinfo *))
{
	int		c_x;
	int		c_y;
	int		c_z;
	t_point	neg_corr;

	c_x = map->points[map->lines / 2][map->width / 2].x;
	c_y = map->points[map->lines / 2][map->width / 2].y;
	c_z = map->points[map->lines / 2][map->width / 2].z;
	printf("cx = %d cy = %d cz = %d\n", c_x, c_y, c_z);
	//printf("(%d ; %d ; %d)\n", map->points[0][0].x, map->points[0][0].y, map->points[0][0].z);	
	translate_point(-c_x, -c_y, -c_z, map);
	//printf("(%d ; %d ; %d)\n", map->points[0][0].x, map->points[0][0].y, map->points[0][0].z);
	f(angle, map);
	fix_neg(map);
	translate_point(c_x, c_y, c_z, map);
	//printf("(%d ; %d ; %d)\n", map->points[0][0].x, map->points[0][0].y, map->points[0][0].z);
}

void	rotate_x(float angle, t_mapinfo *map)
{
	float	y1;
	float	z1;
	int		u;
	int		v;

	v = 0;
	while (v < map->lines)
	{
		u = 0;
		while (u < map->width)
		{
			y1 = map->points[v][u].y * cos(angle) - map->points[v][u].z * sin(angle);
			z1 = map->points[v][u].z * cos(angle) + map->points[v][u].y * sin(angle);
			map->points[v][u].y = y1;
			map->points[v][u].z = z1;
			u++;
		}
		v++;
	}
}

void	rotate_y(float angle, t_mapinfo *map)
{
	float	x1;
	float	z1;
	int		i;
	int		u;
	int		v;

	v = 0;
	while (v < map->lines)
	{
		u = 0;
		while (u < map->width)
		{
			x1 = map->points[v][u].x * cos(angle) - map->points[v][u].z * sin(angle);
			z1 = map->points[v][u].z * cos(angle) + map->points[v][u].x * sin(angle);
			map->points[v][u].y = x1;
			map->points[v][u].z = z1;
			u++;
		}
		v++;
	}
/*
	while (i < points)
	{	
		x1 = pt[i].x * cos(angle) - pt[i].z * sin(angle);
		z1 = pt[i].z * cos(angle) + pt[i].x * sin(angle);
		pt[i].x = x1;
		pt[i].z = z1;
		i++;
	}
	*/
}

void	rotate_z(float angle, t_mapinfo *map)
{
	float	x1;
	float	y1;
	int		i;

	int		u;
	int		v;

	v = 0;
	while (v < map->lines)
	{
		u = 0;
		while (u < map->width)
		{
			x1 = map->points[v][u].x * cos(angle) - map->points[v][u].y * sin(angle);
			y1 = map->points[v][u].x * sin(angle) + map->points[v][u].y * cos(angle);
			map->points[v][u].x = x1;
			map->points[v][u].y = y1;
			u++;
		}
		v++;
	}
/*
	i = 0;
	while (i < points)
	{	
		x1 = pt[i].x * cos(angle) - pt[i].y * sin(angle);
		y1 = pt[i].x * sin(angle) + pt[i].y * cos(angle);
		pt[i].x = x1;
		pt[i].y = y1;
		i++;
	}
*/
}
