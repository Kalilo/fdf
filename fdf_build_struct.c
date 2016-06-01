/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_build_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:36:52 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/31 15:10:29 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_numbers(char *str)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			ret++;
		 	while (ft_isdigit(str[i]) && str[i])
				i++;
		}
		else
			i++;
	}
	return (ret);
}

int	ft_map(t_mapinfo file, t_point ***cloud)
{
	int		l;
	int		c;
	char 	**split_line;
	int		d_count;
	t_point	**new;

	l = 0;
	d_count = count_numbers(file.map[l]);
	new = (t_point**)malloc(sizeof(t_point*) * file.lines);
	while (l < file.lines)
	{
		new[l] = (t_point*)malloc(sizeof(t_point) * d_count);
		c = 0;
		split_line = ft_strsplit(file.map[l], ' ');
		while (c < d_count)
		{
			new[l][c] = new_point(c, (float)ft_atoi(split_line[c]), l);
			c++;
		}
		free(split_line);
		l++;
	}
	*cloud = new;
	return (d_count);
}
