/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:41:32 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/02 15:38:15 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			count_lines(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("Error opening file.\n");
		exit(-1);
	}
	while (get_next_line(fd, &line))
	{
		lines++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (lines);
}

t_mapinfo			read_map(char *filename)
{
	char		*line;
	t_mapinfo	file;
	int			fd;
	int			i;

	i = 0;
	file.lines = 0;
	file.map = NULL;
	if (!(fd = open(filename, O_RDONLY)))
		return (file);
	file.lines = count_lines(filename);
	file.map = (char**)malloc(sizeof(char*) * file.lines);
	while (i < file.lines)
	{
		get_next_line(fd, &line);
		file.map[i++] = line;
	}
	close(fd);
	return (file);
}

void				free_file(t_mapinfo map)
{
	int l;

	l = 0;
	while (l < map.lines)
	{
		free(map.map[l]);
		l++;
	}
	free(map.map);
}
