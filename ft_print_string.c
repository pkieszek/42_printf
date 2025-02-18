# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_print_string.c                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 18:15:39 by pkieszek          #+#    #+#              #
#    Updated: 2025/02/18 18:15:51 by pkieszek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "ft_printf.h"
#include "libft.h"

/* Function to print a string and return its length */
int ft_print_string(va_list args)
{
    char *str;
    int len;

    str = va_arg(args, char *); // Retrieve string argument
    if (!str) // Handle NULL string case
        str = "(null)";
    
    ft_putstr_fd(str, 1); // Print the string
    len = ft_strlen(str); // Get the length of the printed string
    
    return (len); // Return the total number of printed characters
}
