/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:42:05 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/31 07:52:06 by ddu-toit         ###   ########.fr       */
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

void	init_file(t_mapinfo *file, char **argv, int err)
{
	if (err != 2)
	{
		file->scale_x = ft_atoi(argv[2]);
		file->scale_y = ft_atoi(argv[3]);
	}
	else
	{
		file->scale_x = DEFAULT_SCALE;
		file->scale_y = DEFAULT_SCALE;
	}
}

int	main(int argc, char **argv)
{
	t_mapinfo	file;
	int			points_c;
	int			err;
	int	i = 0;
			
	printf("Commencing things\n");
	err = (ft_argcheck(argc, argv, &file))
	init_file(
	if (err == 0)
	{
		file = read_map(argv[1]);
		while (i < file.lines)
		{
			printf("map[%d] = %s\n",i, file.map[i]);
			i++;
		}
		file.width = map(file, &file.points);
		print_cloud(file);
		file.points_num = file.lines * file.width;
		ft_init_map(file);
	}
}
