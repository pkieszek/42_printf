# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 12:55:17 by pkieszek          #+#    #+#              #
#    Updated: 2025/02/05 19:30:55 by pkieszek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
       ft_print_char.c \
       ft_print_string.c \
       ft_print_int.c \
       ft_print_unsigned.c \
       ft_print_hex.c \
       ft_print_pointer.c

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

# Default target to build the library
all: $(NAME)

# Rule to compile .c files into .o object files
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the library
$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(LIBFT)

# Rule to make the libft.a (located in ./libft)
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean object files and libft.a
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

# Clean all (including the final library)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Rebuild everything (clean + all)
re: fclean all
