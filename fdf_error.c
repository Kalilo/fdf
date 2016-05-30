/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 09:50:25 by meckhard          #+#    #+#             */
/*   Updated: 2016/05/30 12:54:28 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_argcheck(int argc, char **argv, t_mapinfo *map)
{
	if (argc == 2)
		return (0);
	if (argc != 4)
	{
		printf("Usage : ./fdf <filename> [ case_size z_size ]\n");
		return (-1);
	}	
	else 
	{
		if ((ft_atoi(argv[2]) == 0) || (ft_atoi(argv[3]) == 0))
		{
			printf("Usage : ./fdf <filename> [ case_size z_size ]\n");
			return (-1);
		}
		else
		{
			map->scale_x = ft_atoi(argv[2]);
			map->scale_y = ft_atoi(argv[3]);
		}
	}
	return (0);
}
