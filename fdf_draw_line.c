/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 19:51:54 by reyvan-d          #+#    #+#             */
/*   Updated: 2016/06/04 08:37:59 by reyvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_point(t_point p1, t_point p2, t_mapinfo *m, t_line_var lvar)
{
	while (!(p1.x == p2.x && p1.z == p2.z))
	{
		lvar.e2 = lvar.err;
		if (lvar.e2 > -lvar.dx)
		{
			lvar.err -= lvar.dy;
			p1.x += lvar.sx;
		}
		if (lvar.e2 < lvar.dy)
		{
			lvar.err += lvar.dx;
			p1.z += lvar.sy;
		}
		mlx_pixel_put(m->mlx, m->win, p1.x, p1.z, 0xFFFFFF);
	}
}

void		draw_line(t_point p1, t_point p2, t_mapinfo *m)
{
	t_line_var	lvar;

	lvar.dx = abs(p2.x - p1.x);
	lvar.sx = p1.x < p2.x ? 1 : -1;
	lvar.dy = abs(p2.z - p1.z);
	lvar.sy = p1.z < p2.z ? 1 : -1;
	lvar.err = (lvar.dx > lvar.dy ? lvar.dx : -lvar.dy) / 2;
	mlx_pixel_put(m->mlx, m->win, p1.x, p1.z, 0xFFFFFF);
	draw_point(p1, p2, m, lvar);
}
