# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 14:32:57 by rkowalsk          #+#    #+#              #
#    Updated: 2020/02/17 15:48:31 by rkowalsk         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =	srcs/ft_printf.c \
		srcs/ft_uitox.c \
		srcs/ft_params.c \
		srcs/ft_params_di.c \
		srcs/ft_params_uxx.c \
		srcs/ft_params_p.c \
		srcs/ft_params_s.c
FLAGS = -Wall -Wextra -Werror
HEADER = includes
LIB_NAME = libft/libft.a
OBJS = ${SRCS:.c=.o}

.PHONY: all
.PHONY: clean
.PHONY: fclean
.PHONY: re

$(NAME): $(OBJS) $(LIB_NAME)
	cp $(LIB_NAME) ./$(NAME)
	ar rc $(NAME) $(OBJS)

%o: %c $(HEADER)
	gcc $(FLAGS) -I$(HEADER) -c $< -o $@

$(LIB_NAME):
	cd libft && make all

all: $(NAME)

clean:
	rm -f $(OBJS)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all