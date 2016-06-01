/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:00:47 by meckhard          #+#    #+#             */
/*   Updated: 2016/06/01 13:56:59 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_mapinfo *map)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 12)
		rotate_y(-5, map);
	if (keycode == 14)
		rotate_y(5, map);
	mlx_clear_window(0, map->win);
	ft_centremap(map);
	ft_draw_map(*map);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
