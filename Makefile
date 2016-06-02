# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/02 15:19:49 by daviwel           #+#    #+#              #
#    Updated: 2016/06/02 15:49:32 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FILES = fdf_build_struct.c fdf_draw.c fdf_draw_line.c fdf_error.c \
		fdf_keyhook.c fdf_main.c fdf_movemap.c fdf_point.c \
		fdf_point_rotation.c fdf_read_file.c

OBJECTS = $(FILES:.c=.o)

CFLAG = -Wall -Werror -Wextra

ATTACH = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc $(CFLAG) -I libft/ -c $(FILES)
	gcc $(CFLAG) -o $(NAME) $(OBJECTS) $(ATTACH)

clean:
	/bin/rm -f $(OBJECTS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

norme:
	norminette $(FILES)
