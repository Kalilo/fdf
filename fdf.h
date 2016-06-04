/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 14:21:42 by khansman          #+#    #+#             */
/*   Updated: 2016/06/04 14:21:48 by khansman         ###   ########.fr       */
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
# define ANGL 5

# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define YELLOW 0x00B08000
# define BLUE 0x000000FF
# define GRAY 0x808080
# define BROWN 0xAD4F09

# define L_Q 12
# define L_W 13
# define L_E 14
# define L_A 0
# define L_S 1
# define L_D 2
# define L_R 15
# define K_UP 126
# define K_DOWN 125
# define K_LEFT 123
# define K_RIGHT 124
# define ESC 53
# define NUM_0 82
# define NUM_1 83
# define NUM_2 84
# define NUM_3 85
# define NUM_4 86
# define NUM_5 87
# define NUM_6 88
# define NUM_7 89
# define NUM_8 90
# define NUM_9 92
# define MINUS 78
# define PLUS 69

# define INIT_X 245
# define INIT_Y 110
# define INIT_Z -125

# define CON_ONE str[k] == ',' || str[k] == 'x'
# define CON_TWO fabs((double)(p1.x - p2.x))
# define CON_THREE fabs((double)(p1.z - p2.z))
# define MAP_POINT map->points[v][u]

# define INFO01 "Q and E for y rotation"
# define INFO02 "A and D for x rotation"
# define INFO03 "W and S for z rotation"
# define INFO04 "Arrows for scale. R to reset"
# define INFO05 "I displays these instructions"

typedef struct		s_point
{
	long int	x;
	long int	y;
	long int	z;
	long int	col;
}					t_point;

typedef struct		s_mapinfo
{
	char	**map;

	long int	lines;
	long int	width;

	long int	points_num;
	void		*mlx;
	void		*win;
	t_point		**points;
	long int	scale_x;
	long int	scale_y;
	float		rot_x;
	float		rot_y;
	float		rot_z;
	long int	ori_x;
	long int	ori_y;
}					t_mapinfo;

typedef struct		s_line_var
{
	long int	dx;
	long int	sx;
	long int	dy;
	long int	sy;
	long int	err;
	long int	e2;
}					t_line_var;

t_point				new_point(long int x, long int y, long int z);
void				translate_point(long int x, long int y, long int 
						z, t_mapinfo *map);
void				translate_rot(float angle, t_mapinfo *map,
						void (f)(float, t_mapinfo *));
void				scale_points(t_mapinfo *map, long int scale_x, 
						long int scale_y);
void				rotate_x(float angle, t_mapinfo *map);
void				rotate_y(float angle, t_mapinfo *map);
void				rotate_z(float angle, t_mapinfo *map);
t_mapinfo			read_map(char *filename);
void				ft_map(t_mapinfo *map, t_point ***cloud);
void				ft_init_map(t_mapinfo *mapinfo);
int					ft_argcheck(int argc, char **argv);
void				draw_line(t_point v1, t_point v2, t_mapinfo *m);
void				ft_movemap(t_mapinfo *map, long int offset_x, 
						long int offset_y);
void				ft_centremap(t_mapinfo *map);
void				ft_draw_map(t_mapinfo map);
void				ft_draw_instruct(t_mapinfo map);
int					key_hook(int keycode, t_mapinfo *map);
t_point				**ft_mapcopy(t_mapinfo *map);
void				free_map(t_mapinfo map);
void				free_file(t_mapinfo map);

#endif
