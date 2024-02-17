# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 18:03:30 by agondan-          #+#    #+#              #
#    Updated: 2024/02/02 16:26:58 by agondan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_putnbr.c ft_str.c ft_printhex.c ft_putlong.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -sC libft bonus
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	rm -rf libft/*.o
	rm -rf libft/libft.a

fclean: clean
	rm -f $(NAME)

re: fclean all
