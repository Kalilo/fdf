# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/02 15:19:49 by daviwel           #+#    #+#              #
#    Updated: 2016/06/03 18:25:04 by ghavenga         ###   ########.fr        #
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

quick: clean $(NAME)
	@echo "Made Quickly"

lib:
	@make -C libft/ fclean
	@make -C libft/

$(NAME): lib
	@gcc $(CFLAG) -I libft/ -c $(FILES)
	@gcc $(CFLAG) -o $(NAME) $(OBJECTS) $(ATTACH)
	@echo "fdf Successfully Compiled"

clean:
	@/bin/rm -f $(OBJECTS)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norme:
	@clear
	@norminette $(FILES)

test:
	@./fdf ../collab_fdf/test_maps/42.fdf
