#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 15:13:13 by etheodor          #+#    #+#              #
#    Updated: 2015/01/05 09:44:47 by etheodor         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

CFLAG = -Wall -Werror -Wextra -I ./includes

MINILIBX = -L/usr/x11/lib -lmlx -lXext -lX11

LIBFT = ./libft/includes

SOURCE = ./srcs/main.c \
		./srcs/ft_mlx_tools.c \
		./srcs/ft_error.c \
		./srcs/ft_error2.c \
		./srcs/ft_fractals.c \
		./srcs/ft_mlx_hook.c

POINTO = main.o \
		ft_mlx_tools.o \
		ft_error.o \
		ft_error2.o \
		ft_fractals.o \
		ft_mlx_hook.o

all: $(NAME)
	@echo "all: OK"

$(NAME):
	@make -C libft/ fclean
	@make -C libft
	@make -C libft/ clean
	@gcc -c -g $(CFLAG) $(SOURCE) -I $(LIBFT)
	@gcc $(CFLAG) -o $(NAME) $(POINTO) ./libft/libft.a -L/usr/x11/lib -lmlx -lXext -lX11
	@make clean

test:
	@gcc -c -g $(CFLAG) $(SOURCE)
	@gcc $(CFLAG) -o $(NAME) $(POINTO) ./libft/libft.a -L/usr/x11/lib -lmlx -lXext -lX11
	@make clean
	@echo "test: OK"

clean:
	@rm -rf $(POINTO)

fclean: clean
	@rm -rf $(NAME)
	@echo "fclean: OK"

re: fclean all

.PHONY: re fclean clean all $(NAME) test
