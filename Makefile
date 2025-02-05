# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 12:55:17 by pkieszek          #+#    #+#              #
#    Updated: 2025/02/05 16:26:26 by pkieszek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
    ar rcs $(NAME) $(OBJS)

$(LIBFT):
    make -C $(LIBFT_DIR)

clean:
    rm -f $(OBJS)
    make clean -C $(LIBFT_DIR)

fclean: clean
    rm -f $(NAME)
    make fclean -C $(LIBFT_DIR)

re: fclean all