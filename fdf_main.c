/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:42:05 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/30 14:53:15 by daviwel          ###   ########.fr       */
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
			//printf("point[%d][%d] : (%d ; %d ; %d)\n", l , c, map.points[l][c].x, map.points[l][c].y, map.points[l][c].z);
			c++;
		}
		l++;
	}
}

int	main(int argc, char **argv)
{
	t_mapinfo	file;
	t_point		**cloud;
	int			points_c;
	int	i = 0;
			
	printf("Commencing things\n");
	if ((ft_argcheck(argc, argv, &file)) == 0)
	{
		file = read_map(argv[1]);
		printf("lines = %d\n", file.lines);
		while (i < file.lines)
		{
			printf("map[%d] = %s\n",i, file.map[i]);
			i++;
		}
		file.width = map(file, &file.points);
		printf("points = %d\n", file.width);
		//file.width = pointsfile.lines;
		print_cloud(file);
		file.points_num = points_c;
		//file.points = cloud;
		ft_init_map(file);
	//	print_cloud(cloud, 1);
	}
}
