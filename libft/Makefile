#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 15:18:52 by etheodor          #+#    #+#              #
#    Updated: 2014/11/14 15:05:38 by etheodor         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libft.a

CFLAG = -Wall -Werror -Wextra 

SOURCE = ft_putchar.c \
ft_putstr.c \
ft_memset.c \
ft_putnbr.c \
ft_bzero.c \
ft_strlen.c \
ft_strdup.c \
ft_strcpy.c \
ft_strncpy.c \
ft_strstr.c \
ft_strcmp.c \
ft_strncmp.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memchr.c \
ft_strcat.c \
ft_memmove.c \
ft_memcmp.c \
ft_strncat.c \
ft_strchr.c \
ft_strrchr.c \
ft_strnstr.c \
ft_atoi.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_toupper.c \
ft_tolower.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putnbr_fd.c \
ft_memalloc.c \
ft_memdel.c \
ft_strnew.c \
ft_strdel.c \
ft_strclr.c \
ft_striter.c \
ft_striteri.c \
ft_strmap.c \
ft_strmapi.c \
ft_strequ.c \
ft_strnequ.c \
ft_strjoin.c \
ft_strtrim.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_strsub.c \
ft_itoa.c \
ft_strsplit.c 

POINTO = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(CFLAG) -c $(SOURCE) -I includes
	@ar rc libft.a $(POINTO)
	@ranlib libft.a
test:
	@gcc $(CFLAG) test_libft.c libft.a

clean:
	@rm -rf $(POINTO)


fclean: clean
	@rm -rf $(NAME)

re: fclean all