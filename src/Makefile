# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 10:31:46 by epresa-c          #+#    #+#              #
#    Updated: 2022/09/19 17:00:03 by olmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = miniRT

NAMELIBFT = libft.a

SRCS = main.c utils.c vector_utils.c raytracing.c intersection.c \
	   vector_utils2.c node_t_obj_create.c node_t_obj_utils.c  \
	   vector_utils3.c parsing.c init_elements.c utils2.c check_parsing.c \
	   utils3.c intersection2.c

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

CC = gcc

LIBFTPATH = ../libft/

MLXPATH = ../mlx

all: $(NAME)

$(NAME): $(OBJ)
	# make -C $(LIBFTPATH)
	# make -C $(MLXPATH)
	${CC} ${CFLAGS} -I $(MLXPATH) $(SRCS) -L $(MLXPATH) $(LIBFTPATH)$(NAMELIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)
	# make clean -C $(LIBFTPATH)
	# make clean -C $(MLXPATH)

fclean: clean
	rm -rf $(NAME)
	# make fclean -C $(LIBFTPATH)

re: fclean all

.PHONY: all clean fclean re
