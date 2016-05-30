/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:42:05 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/30 12:57:15 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_cloud(t_point *cloud, int points)
{
	int	i;
	i = 0;
	while (i < points)
	{
		printf("point[%d] : (%d ; %d ; %d)\n", i + 1, cloud[i].x, cloud[i].y, cloud[i].z);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_mapinfo	file;
	t_point		*cloud;
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
		points_c = map(file, &cloud);
		printf("points = %d\n", points_c);
		//print_cloud(cloud, points_c);
		file.points_num = points_c;
		file.points = cloud;
		ft_init_map(file);
		print_cloud(cloud, 1);
	}
}
