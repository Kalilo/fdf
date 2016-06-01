/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:24:05 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/01 08:18:09 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_fabs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

float	ft_fmax(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_fmin(float a, float b)
{
	if (a > b)
		return (b);
	return (a);
}

void	draw_line(t_point v1, t_point v2, t_mapinfo *m)
{
	float	step;
	float	t;
	int		col;
	t_point	sum;

	t = 0;
	if (v1.y > 0 && v2.y > 0)
		col = 0x00FF0000;
	else
		col = 0x00FFFFFF;
	step = (float)(1 / (ft_fmax(ft_fabs(v1.x - v2.x), ft_fabs(v1.z - v2.z)) *
				2));
	while (t <= 1)
	{
		sum.x = v1.x + t * (v2.x - v1.x);
		sum.y = v1.y + t * (v2.y - v1.y);
		sum.z = v1.z + t * (v2.z - v1.z);
		mlx_pixel_put(m->mlx, m->win, sum.x, sum.z, col);
		t = t + step;
	}
}
