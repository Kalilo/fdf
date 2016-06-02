/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_build_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:36:52 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/02 15:27:39 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_numbers(char *str)
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
			while ((ft_isdigit(str[i]) && str[i])
					|| str[i] == ',' || str[i] == 'x')
				i++;
		}
		else
			i++;
	}
	return (ret);
}

void			ft_map(t_mapinfo *map, t_point ***cloud)
{
	int		l;
	int		c;
	char	**split_line;
	t_point	**new;

	l = 0;
	map->width = count_numbers(map->map[l]);
	new = (t_point**)malloc(sizeof(t_point*) * map->lines);
	while (l < map->lines)
	{
		new[l] = (t_point*)malloc(sizeof(t_point) * map->width);
		c = 0;
		split_line = ft_strsplit(map->map[l], ' ');
		while (c < map->width)
		{
			new[l][c] = new_point(c, ft_atoi(split_line[c]), l);
			c++;
		}
		free(split_line);
		l++;
	}
	*cloud = new;
}

t_point			**ft_mapcopy(t_mapinfo *map)
{
	int		l;
	int		c;
	t_point	**new;

	l = 0;
	new = (t_point**)malloc(sizeof(t_point*) * map->lines);
	while (l < map->lines)
	{
		new[l] = (t_point*)malloc(sizeof(t_point) * map->width);
		c = 0;
		while (c < map->width)
		{
			new[l][c] = map->points[l][c];
			c++;
		}
		l++;
	}
	return (new);
}

void			free_map(t_mapinfo map)
{
	int		v;

	v = 0;
	while (v < map.lines)
	{
		free(map.points[v]);
		v++;
	}
	free(map.points);
	map.points = NULL;
}
