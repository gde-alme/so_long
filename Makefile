# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 17:22:12 by gde-alme          #+#    #+#              #
#    Updated: 2022/09/12 16:56:11 by gde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= so_long

SRCS	= srcs/close_game.c srcs/movement.c srcs/map_display.c srcs/utils.c srcs/main.c srcs/create_map.c srcs/gnl.c srcs/gnl_utils.c srcs/utils2.c
OBJS	= ${SRCS:.c=.o}

HEADER	= -Iincludes
CC	= gcc
CFLAGS  = -Wall -Wextra -Werror
Inc	= -I./minilibx-linux -Imlx_linux -O3

RM		= rm -rf
AR		= ar rc
RN		= ranlib


.c.o:	
			${CC} -c ${CFLAGS} ${Inc} ${HEADER} -o $@ $<

all: 		 ${PROG}
			${CC} ${OBJS} -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o ${PROG}

${PROG}: ${OBJS}
			${AR} ${PROG} ${OBJS}
			${RN} ${PROG}
clean:
			${RM} ${OBJS} ${PROG}

re: 		fclean all

.PHONY: all clean fclean re
