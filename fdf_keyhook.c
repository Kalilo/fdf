/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:00:47 by meckhard          #+#    #+#             */
/*   Updated: 2016/06/01 13:30:58 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_mapinfo *map)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 12)
		ft_putstr("left");
	if (keycode == 14)
		ft_putstr("right");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
