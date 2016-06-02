/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_build_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:36:52 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/02 13:06:08 by daviwel          ###   ########.fr       */
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
		 	while ((ft_isdigit(str[i]) && str[i]) || str[i] == ',' || str[i] == 'x')
				i++;
		}
		else
			i++;
	}
	return (ret);
}

int		ft_to_hex(char	*s)
{
	int	result;

	result = 0;
}

int		ft_det_col(t_mapinfo *map, char *str)
{
	char	*crawl;

	crawl = str;
	while (*crawl != ' ' && *crawl != '\0')
	{
		if (*crawl == ',')
		{
			crawl++;
			ft_putnbr((int)ft_strsub(crawl, 0, 8));
			ft_putchar('\n');
			return (ft_strsub(crawl, 0, 8));
		}
		crawl++;
	}
	return (0x00FFFFFF);
}

void	ft_map(t_mapinfo *map, t_point ***cloud)
{
	int		l;
	int		c;
	char 	**split_line;
	int		col;
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
			col = ft_det_col(map, split_line[c]);
			new[l][c] = new_point(c, ft_atoi(split_line[c]), l, col);
			c++;
		}
		free(split_line);
		l++;
	}
	*cloud = new;
}

t_point	**ft_mapcopy(t_mapinfo *map)
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

void	free_map(t_mapinfo map)
{
	int     u;
	int     v;

	 v = 0;
	 while (v < map.lines)
	 {
		free(map.points[v]);
		v++;
	}
	free(map.points);
	map.points = NULL;
}
