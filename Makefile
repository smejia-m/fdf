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

SRC = fdf.c 

OBJ		= $(SRC:.c=.o)

INC_DIR	= ./inc/

SRC		= ficher_struct_fdf.c

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g

LIBLINK	= -L ./libft -lft 


all: $(NAME)

lib_make:
	make -C ./libft

$(NAME): lib_make $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBLINK)

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