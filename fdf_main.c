/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:42:05 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/27 16:23:25 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_cloud(t_point *cloud, int points)
{
	int	i;
	i = 0;
	while (i < points)
	{
		printf("point[%d] : (%.1f ; %.1f ; %.1f)\n", i + 1, cloud[i].x, cloud[i].y, cloud[i].z);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_mapinfo	file;
	t_point		*cloud;
	int			points_c;
	int	i = 0;
			
	ft_printf("Commencing things\n");
	file = read_map(argv[1]);
	ft_printf("lines = %d\n", file.lines);
	while (i < file.lines)
	{
		ft_printf("map[%d] = %s\n",i, file.map[i]);
		i++;
	}
	points_c = map(file, &cloud);
	ft_printf("points = %d\n", points_c);
	print_cloud(cloud, 1);
	translate_point(5, 5, 5, cloud);
	ft_printf("translated by 5 ,5, 5\n");
	print_cloud(cloud, 1);
}
