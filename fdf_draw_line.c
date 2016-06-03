/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 19:51:54 by reyvan-d          #+#    #+#             */
/*   Updated: 2016/06/03 20:40:03 by reyvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point p1, t_point p2, t_mapinfo *m)
{
	int dx = abs(p2.x-p1.x), sx = p1.x<p2.x ? 1 : -1;
	int dy = abs(p2.y-p1.y), sy = p1.y<p2.y ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;

	for(;;){
	mlx_pixel_put(m->mlx, m->win, p1.x, p1.y, 0xFFFFFF);
	if (p1.x == p2.x && p1.y == p2.y) break;
	e2 = err;
	if (e2 >-dx) { err -= dy; p1.x += sx; }
	if (e2 < dy) { err += dx; p1.y += sy; }
	}
}
