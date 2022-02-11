# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 17:18:12 by tgerdes           #+#    #+#              #
#    Updated: 2022/01/18 01:06:41 by tgerdes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c map.c player.c window.c keys.c images.c map_check.c

OBJS = ${SRCS:.c=.o}

LIBFT = ./libft

CC = gcc

RM = rm -fr

CFLAGS = -Wall -Wextra -Werror

EXT_LIB = libmlx.a

UNAME := $(shell uname)

all: ${EXT_LIB} libft.a ${NAME}

ifeq ($(UNAME), Linux)
MINILIBX = ./mlx

%.o: %.c
		${CC} ${CFLAGS} -I/usr/include -Imlx -O3 -c $< -o ${<:.c=.o}

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(EXT_LIB) -g $(CFLAGS) -L/usr/include/X11/extensions -lX11 -lXext -L $(LIBFT) -lft -o $(NAME)

endif

ifeq ($(UNAME), Darwin)
MINILIBX = ./mlxmac

%.o: %.c
		${CC} ${CFLAGS} -Imlxmac -c $< -o ${<:.c=.o}

$(NAME): $(SRCS)
	$(CC) -Lmlx -L $(MINILIBX) -lmlx -framework OpenGL -framework AppKit -L $(LIBFT) -lft $(SRCS) -o $(NAME)

endif

${EXT_LIB}:
	make -C ${MINILIBX}
	cp ${MINILIBX}/${EXT_LIB} .
	cp ${MINILIBX}/mlx.h .

libft.a:
	make -C ${LIBFT}

archive:
	ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS} a.out mlx.h

fclean: clean
		${RM} ${NAME} ${EXT_LIB}
		make -C ${LIBFT} fclean
		make -C ${MINILIBX} clean

re:		fclean all
