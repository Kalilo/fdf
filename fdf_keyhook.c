/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:00:47 by meckhard          #+#    #+#             */
/*   Updated: 2016/06/01 15:35:41 by ddu-toit         ###   ########.fr       */
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
		rotate_y(-5, &mapcpy);
	if (keycode == 14)
		rotate_y(5, &mapcpy);
	mlx_clear_window(0, map->win);
	ft_centremap(&mapcpy);
	ft_draw_map(mapcpy);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
