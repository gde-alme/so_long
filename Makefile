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
CC	= gcc -Wall -Wextra -Werror
Inc	= -I./minilibx-linux -Imlx_linux -O3

RM		= rm -f
AR		= ar rc
RN		= ranlib


.c.o:		%.o : %.c
					${CC} ${Inc} ${HEADER} -c $< -o $(<:.c=.o)

all: 		install ${PROG}
			${CC} ${OBJS} -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o ${PROG}
install:
			curl -LJO https://projects.intra.42.fr/uploads/document/document/10440/minilibx-linux.tgz
			tar -xf minilibx-linux.tgz
			rm -rf minilibx-linux.tgz
			make -C minilibx-linux
${PROG}: ${OBJS}
			${AR} ${PROG} ${OBJS}
			${RN} ${PROG}
clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${PROG}

re: 		fclean
			${CC} ${OBJS} -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o ${PROG}

.PHONY: all install clean fclean re
