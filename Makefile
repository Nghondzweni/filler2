# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnghondz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 15:59:34 by tnghondz          #+#    #+#              #
#    Updated: 2018/08/02 14:48:08 by tnghondz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/tnghondz.filler

RCS_DIR		= ./resources

SRCS_DIR	:= ./srcs/filler.c
SRCS_DIR	+= ./srcs/algo.c
SRCS_DIR	+= ./srcs/check_send.c
SRCS_DIR	+= ./srcs/read.c
SRCS_DIR	+= ./srcs/trim.c

LIBFT_DIR	= ./libft

INCLUDES	= ./includes

FLAGS = -Wextra -Werror -Wall  -I./includes

CC = gcc

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) -o $(NAME) $(FLAGS) $(SRCS_DIR) libft/libft.a

clean:
	make clean -C libft
	rm -f $(NAME)
fclean:
	make fclean -C libft
	rm ./players/tnghondz.filler

re:
	fclean all
