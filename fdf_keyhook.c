/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:00:47 by meckhard          #+#    #+#             */
/*   Updated: 2016/06/01 16:18:02 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_mapinfo *map)
{
	t_mapinfo mapcpy;

	mapcpy = *map;
	mapcpy.points = ft_mapcopy(map);
	if (keycode == 53)
		exit(0);
	if (keycode == 12)
		map->rot_y -= 5;
	if (keycode == 14)
		map->rot_y += 5;
	mlx_clear_window(0, map->win);	
	to_iso(&mapcpy);
	rotate_x(45, &mapcpy);
	rotate_y(map->rot_y, &mapcpy);	
	ft_centremap(&mapcpy);
	ft_draw_map(mapcpy);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
