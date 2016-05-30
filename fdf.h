/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:30:36 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/30 08:15:13 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libc.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# define WIN_X 400
# define WIN_Y 400

typedef struct		s_point
{
	float	x;
	float	y;
	float	z;
}					t_point;

typedef struct		s_mapinfo
{
	char	**map;
	int		lines;
	int		points_num;
	void	*mlx;
	void	*win;
	t_point	*points;
}					t_mapinfo;

t_point				new_point(float x, float y, float z);

void				translate_point(float x, float y, float z, t_point *point);

void				scale_cloud(t_point *point, float scale_f, int points);

void				project_mod(t_point *point, int points, float mod);

void				rotate_x(float angle, t_point *pt, int points);

void				rotate_y(float angle, t_point *pt, int points);

void				rotate_z(float angle, t_point *pt, int points);

int					count_lines(char *filename);

t_mapinfo			read_map(char* filename);

int					map(t_mapinfo file, t_point **cloud);

void				ft_init_map(t_mapinfo mapinfo);

#endif
