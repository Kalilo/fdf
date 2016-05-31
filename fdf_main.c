/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:42:05 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/31 15:07:24 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_cloud(t_mapinfo map)
{
	int	l;
	int c;
	l = 0;
	c = 0;
	while (l < map.lines)
	{
		c = 0;
		while (c < map.width)
		{
			printf("point[%d][%d] : (%d ; %d ; %d)\n", l , c, map.points[l][c].x, map.points[l][c].y, map.points[l][c].z);
			c++;
		}
		l++;
	}
}

void	init_map(t_mapinfo *map, char **argv, int err)
{
	if (err != 2)
	{
		map->scale_x = ft_atoi(argv[2]);
		map->scale_y = ft_atoi(argv[3]);
	}
	else
	{
		map->scale_x = DEFAULT_SCALE;
		map->scale_y = DEFAULT_SCALE;
	}
	map->points_num = map->lines * map->width;
}

int	my_key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mapinfo	map;
	int			points_c;
	int			err;
	int	i = 0;
			
	printf("Commencing things\n");
	map = read_map(argv[1]);
	err = (ft_argcheck(argc, argv));
	init_map(&map, argv, err);
	map.width = ft_map(map, &map.points);
	while (i < map.lines)
	{
		printf("map[%d] = %s\n",i, map.map[i]);
		i++;
	}
	//print_cloud(map);
	ft_init_map(&map);
	ft_draw_map(map);
	mlx_key_hook(map.win, my_key_funct, 0);
	mlx_loop(map.mlx);
}
