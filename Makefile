#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 11:07:23 by smejia-m          #+#    #+#              #
#    Updated: 2016/09/28 11:07:28 by smejia-m         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = main.c fdf.c ft_parsing.c ft_tracer.c ft_graph.c ft_reader.c ft_init.c

OBJ		= $(SRC:.c=.o)

INC_DIR	= ./inc/

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g

LIBLINK	= -L ./libft -lft 

MLXLIBS = -L/usr/local/lib/ -I/usr/local/include -lmlx 

FRAMEWORKS = -framework OpenGL -framework AppKit

all: $(NAME)

lib_make:
	make -C ./libft

$(NAME): lib_make $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBLINK) $(MLXLIBS) $(FRAMEWORKS) 

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $< 
	

.PHONY: clean fclean

clean:
	/bin/rm -rf $(OBJ)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all