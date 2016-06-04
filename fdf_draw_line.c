/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:55:28 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/04 08:40:51 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				colourpicker(t_point p1, t_point p2, float k)
{
	int			col;
	
	if (p1.col == 1 && p2.col == 1)
		col = YELLOW;
	else if (p1.col == 1 || p2.col == 1)
	{
		if (p2.z < p1.z)
			col = (RED + GRAY) - (k * 100);
		else
			col = (RED + GRAY) - ((1 - k) * 100);
	}
	else
		col = GRAY;
	return (col);
}


void			draw_line(t_point p1, t_point p2, t_mapinfo *m)
{
	float	step;
	float	k;
	int		col;
	t_point	sum;

	k = 0;
	step = (float)pow((fmax(CON_TWO, CON_THREE)), -1);
	while (k <= 1)
	{
		col = colourpicker(p1, p2, k);
		sum.x = p1.x + k * (p2.x - p1.x);
		//sum.y = p1.y + k * (p2.y - p1.y);
		sum.z = p1.z + k * (p2.z - p1.z);
		mlx_pixel_put(m->mlx, m->win, sum.x, sum.z, col);
		k += step;
	}
}
