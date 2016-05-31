/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:30:36 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/31 14:58:05 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libc.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# define WIN_X 800
# define WIN_Y 600
# define DEFAULT_SCALE 20

typedef struct		s_point
{
	int	x;
	int	y;
	int	z;
	int	col;
}					t_point;

typedef struct		s_mapinfo
{
	char	**map;
	int		lines;
	int		width;
	int		points_num;
	void	*mlx;
	void	*win;
	t_point	**points;
	int		scale_x;
	int		scale_y;
}					t_mapinfo;

t_point				new_point(int x, int y, int z);

void				translate_point(int x, int y, int z, t_mapinfo *map);

void				translate_rot(float angle, t_mapinfo *map, void (f)(float, t_mapinfo *));

void				scale_points(t_mapinfo *map, int scale_x, int scale_y);

void				rotate_x(float angle, t_mapinfo *map);

void				rotate_y(float angle, t_mapinfo *map);

void				rotate_z(float angle, t_mapinfo *map);

int					count_lines(char *filename);

t_mapinfo			read_map(char* filename);

int					map(t_mapinfo file, t_point ***cloud);

void				ft_init_map(t_mapinfo mapinfo);

t_point				get_point(int x, int y, t_mapinfo map);

int					ft_argcheck(int argc, char **argv);

void				draw_line(t_point v1, t_point v2, t_mapinfo *m);

void				to_iso(t_mapinfo *map);

void				print_cloud(t_mapinfo map);

void				ft_movemap(t_mapinfo *map, int offset_x, int offset_y);

void				ft_centremap(t_mapinfo *map);

void				ft_draw_map(t_mapinfo map);

#endif
