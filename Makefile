# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 17:22:12 by gde-alme          #+#    #+#              #
#    Updated: 2022/06/18 17:39:16 by gde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= so_long

SRCS	= srcs/main.c
OBJS	= ${SRCS:.c=.o}

HEADER	= -Iincludes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -Ilmx

RM		= rm -f
AR		= ar rc
RN		= ranlib


.c.o:		%.o : %.c
					${CC} ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}
			${CC} ${OBJS} -lmlx -framework OpenGL -framework AppKit -o ${PROG}
${PROG}: ${OBJS}
			${AR} ${PROG} ${OBJS}
			${RN} ${PROG}
clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${PROG}

re: 		fclean all

.PHONY: all clean fclean re
