/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 13:46:57 by khansman          #+#    #+#             */
/*   Updated: 2016/06/04 13:47:01 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_argcheck(int argc, char **argv)
{
	if (argc == 2)
		return (2);
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
	}
	return (0);
}
