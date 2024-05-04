# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aproust <aproust@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 13:04:59 by aproust           #+#    #+#              #
#    Updated: 2023/02/01 13:05:01 by aproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	get_next_line.c\
		get_next_line_utils.c\

OBJS = ${SRCS:.c=.o}

NAME = libget_next_line.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${NAME}

.c.o :
	 ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: $(OBJS)
			ar rcs ${NAME} ${OBJS}
clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${OBJS} ${NAME}

re: fclean all

.PHONY:		all clean fclean re
