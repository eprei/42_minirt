# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 11:47:16 by olmartin          #+#    #+#              #
#    Updated: 2022/09/02 15:36:24 by olmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=  vector_utils.c utils.c main.c


OBJS		= ${SRCS:.c=.o}

NAME		= minirt

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra -g

LIBFLAGS	= -L../libft -lft -L../mlx -lmlx -framework OpenGL -framework AppKit

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${SRCS} ${OBJS}	
			#${MAKE} -C ../libft/
			#${MAKE} -C ../mlx/
			${CC} -o ${NAME} ${LIBFLAGS} ${OBJS}


.PHONY:		all clean fclean  re

clean:	
			${RM} ${OBJS}
			#${MAKE} clean -C ../libft
			#${MAKE} clean -C ../mlx


fclean:		clean
			${RM} ${NAME}
			#${MAKE} fclean -C ../libft

re:			fclean all
