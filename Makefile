# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caboudar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 10:54:33 by caboudar          #+#    #+#              #
#    Updated: 2022/09/01 11:14:02 by caboudar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= 		srcs/push_swap.c                             \

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Werror -Wextra -g

CC		= gcc

RM		= rm -f

INCS    = include

all:	${NAME}

.c.o:
		@$(CC) ${CFLAGS} -I$(INCS) -c $< -o $@

${NAME}:	${OBJS} 
		@${CC} ${CFLAGS} ${OBJS}  -lX11 -lXext -o so_long
		@printf "%s\e[0;32m so_long : Compiling object file into executable\n\e[0m" "-"