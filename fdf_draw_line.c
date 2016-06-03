/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2016/06/03 19:51:54 by reyvan-d          #+#    #+#             */
/*   Updated: 2016/06/03 20:40:03 by reyvan-d         ###   ########.fr       */
=======
/*   Created: 2016/06/02 15:55:28 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/03 20:41:11 by ghavenga         ###   ########.fr       */
>>>>>>> ea788fac41bea95c6e9eb115884e27c5b9910e54
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point p1, t_point p2, t_mapinfo *m)
{
	int dx = abs(p2.x-p1.x), sx = p1.x<p2.x ? 1 : -1;
	int dy = abs(p2.y-p1.y), sy = p1.y<p2.y ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;

<<<<<<< HEAD
	for(;;){
	mlx_pixel_put(m->mlx, m->win, p1.x, p1.y, 0xFFFFFF);
	if (p1.x == p2.x && p1.y == p2.y) break;
	e2 = err;
	if (e2 >-dx) { err -= dy; p1.x += sx; }
	if (e2 < dy) { err += dx; p1.y += sy; }
=======
	k = 0;
	step = (float)pow((fmax(CON_TWO, CON_THREE)), -1);
	while (k <= 1)
	{
		if (p1.z > 5 && p2.col == 5)
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
		sum.x = p1.x + k * (p2.x - p1.x);
		//sum.y = p1.y + k * (p2.y - p1.y);
		sum.z = p1.z + k * (p2.z - p1.z);
		mlx_pixel_put(m->mlx, m->win, sum.x, sum.z, col);
		k += step;
>>>>>>> ea788fac41bea95c6e9eb115884e27c5b9910e54
	}
}
