# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aproust <aproust@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 13:10:08 by aproust           #+#    #+#              #
#    Updated: 2023/02/10 11:53:54 by aproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRAIRY		=	libftprintfgnl/libftprintfgnl.a

SRCS            =	so_long.c put_img.c sl_check_error.c sl_utils.c sl_check_path.c\
					sl_utils_sequel.c sl_utils_the_third.c\

OBJS            =    $(SRCS:.c=.o)

SRCSBONUS		=	so_long_bonus.c sl_counter.c put_img_bonus.c sl_utils_bonus.c\
					sl_check_path_bonus.c sl_check_error_bonus.c sl_utils_sequel_bonus.c\
					sl_utils_the_third_bonus.c sl_utils_final_bonus.c\

OBJSBONUS		=	${SRCSBONUS:.c=.o}

CC              =    gcc -g3
RM              =    rm -f
CFLAGS          =    -Wall -Wextra -Werror

NAME            =    so_long

all:			$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iminilibx-linux -Imlx_linux -Ilibftprintfgnl-O3 -c $< -o $@

$(NAME):	$(OBJS)
			make -C minilibx-linux
			make -C libftprintfgnl
				$(CC) $(CFLAGS) $(OBJS) $(LIBRAIRY) -o $(NAME) -Lminilibx-linux -lmlx_Linux -Lminilibx-linux -lXext -lX11 -lm -lz

bonus: 		${OBJSBONUS}
			make -C libftprintfgnl
				$(CC) $(CFLAGS) ${OBJSBONUS} $(LIBRAIRY) -o $(NAME) -Lminilibx-linux -lmlx_Linux -Lminilibx-linux -lXext -lX11 -lm -lz

clean:
			make -C libftprintfgnl clean
			$(RM) $(OBJS) ${OBJSBONUS}

fclean:         clean
			make -C libftprintfgnl fclean
			$(RM) $(NAME)

re:             fclean $(NAME)

.PHONY:			bonus all clean fclean re
