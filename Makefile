# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rkowalsk <rkowalsk@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/14 14:32:57 by rkowalsk     #+#   ##    ##    #+#        #
#    Updated: 2020/01/14 16:23:38 by rkowalsk    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft_printf.a
SRCS =	srcs/ft_printf.c \
		srcs/ft_uitoa.c \
		srcs/ft_uitox.c
FLAGS = -Wall -Wextra -Werror
HEADER = includes
LIB_NAME = libft/libft.a
OBJS = ${SRCS:.c=.o}

.PHONY: all
.PHONY: clean
.PHONY: fclean
.PHONY: re

$(NAME): $(OBJS) $(LIB_NAME)
	ar rc $(NAME) $(OBJS) $(LIB_NAME)

%o: %c $(HEADER)
	gcc $(FLAGS) -I $(HEADER) -c $< -o $@

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