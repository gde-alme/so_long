# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 17:22:12 by gde-alme          #+#    #+#              #
#    Updated: 2022/07/20 13:53:32 by gde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= so_long

SRCS	= srcs/close_game.c srcs/movement.c srcs/map_display.c srcs/utils.c srcs/main.c srcs/create_map.c srcs/gnl.c srcs/gnl_utils.c 
OBJS	= ${SRCS:.c=.o}

HEADER	= -Iincludes
CC	= gcc
CFLAGS	= -I/Users/gde-alme/minilibx-linux -Imlx_linux -O3

RM		= rm -f
AR		= ar rc
RN		= ranlib


.c.o:		%.o : %.c
					${CC} ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}
			${CC} ${OBJS} -Lmlx_linux -lmlx_Linux -L/Users/gde-alme/minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o ${PROG}
${PROG}: ${OBJS}
			${AR} ${PROG} ${OBJS}
			${RN} ${PROG}
clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${PROG}

re: 		fclean all

.PHONY: all clean fclean re
