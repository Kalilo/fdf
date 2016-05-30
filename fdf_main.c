/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:42:05 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/30 17:14:21 by ddu-toit         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_mapinfo	file;
	t_mapinfo	f_err;
	int			points_c;
	int	i = 0;
			
	printf("Commencing things\n");
	if ((ft_argcheck(argc, argv, &file)) == 0)
	{
		file = read_map(argv[1]);
		file.scale_x = ft_atoi(argv[2]);
		file.scale_y = ft_atoi(argv[3]);
		printf("scale_x = %d, scale_y = %d\n", file.scale_x, file.scale_y);
		printf("lines = %d\n", file.lines);
		while (i < file.lines)
		{
			printf("map[%d] = %s\n",i, file.map[i]);
			i++;
		}
		printf("after print\n");
		file.width = map(file, &file.points);
		printf("points = %d\n", file.width);
		print_cloud(file);
		file.points_num = file.lines * file.width;
		ft_init_map(file);
	}
}
