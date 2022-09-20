# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 10:31:46 by epresa-c          #+#    #+#              #
#    Updated: 2022/09/20 10:34:24 by epresa-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = miniRT

NAMELIBFT = libft.a

SRCS = ./src/main.c ./src/utils.c ./src/vector_utils.c ./src/raytracing.c \
	   ./src/intersection.c ./src/vector_utils2.c ./src/node_t_obj_create.c \
	   ./src/node_t_obj_utils.c ./src/vector_utils3.c ./src/parsing.c \
	   ./src/init_elements.c ./src/utils2.c ./src/check_parsing.c \
	   ./src/utils3.c ./src/intersection2.c ./src/vector_utils4.c

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

CC = gcc

LIBFTPATH = ./libft/

MLXPATH = ./mlx

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTPATH)
	make -C $(MLXPATH)
	${CC} ${CFLAGS} -I $(MLXPATH) $(SRCS) -L $(MLXPATH) $(LIBFTPATH)$(NAMELIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFTPATH)
	make clean -C $(MLXPATH)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFTPATH)

re: fclean all

.PHONY: all clean fclean re
