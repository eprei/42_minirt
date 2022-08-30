# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 10:31:46 by epresa-c          #+#    #+#              #
#    Updated: 2022/08/30 15:36:57 by epresa-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = miniRT

NAMELIBFT = libft.a

SRCS = ./src/main.c

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIBFTPATH = ./libft/

MLXPATH = ./mlx

all: $(NAME)

$(NAME): $(OBJ)
	# make -C $(LIBFTPATH)
	# make -C $(MLXPATH)
	CC -I .$(MLXPATH) $(SRCS) -L $(MLXPATH) $(LIBFTPATH)$(NAMELIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)
	# make clean -C $(LIBFTPATH)
	# make clean -C $(MLXPATH)

fclean: clean
	rm -rf $(NAME)
	# make fclean -C $(LIBFTPATH)

re: fclean all

.PHONY: all clean fclean re
