/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 09:07:15 by khansman          #+#    #+#             */
/*   Updated: 2016/06/05 12:14:50 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 64
# define L_LEN 50
# define NUM_FILES 10
# define MAX_BUFF 800000

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int					get_next_line(const int fd, char **line);

typedef struct		s_buff
{
	char			buff[BUFF_SIZE];
	int				buf_pos;
	int				buf_fd;
	int				eof;
}					t_buff;

#endif
