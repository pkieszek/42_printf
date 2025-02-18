/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:15:37 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 18:02:31 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_print_string(va_list args);
/* Prints a string and returns its length */
static int ft_print_str(char *str)
{
    if (!str) // If the string is NULL, print "(null)" instead
        str = "(null)";
    ft_putstr_fd(str, 1); // Print the string to stdout
    return (ft_strlen(str)); // Return the length of the printed string
}

/* Converts an integer to a string, prints it, and returns its length */
static int ft_print_int(int num)
{
    char *str;
    int len;

    str = ft_itoa(num); // Convert integer to string
    len = ft_strlen(str); // Get the length of the number string
    ft_putstr_fd(str, 1); // Print the number string
    free(str); // Free the allocated memory
    return (len); // Return the length of the printed number
}

/* Function to print a string and return its length */
int ft_print_string(va_list args)
{
    char *str;
    int len;

    str = va_arg(args, char *); // Retrieve string argument
    if (!str) // Check if the string is NULL
        str = "(null)"; // Assign "(null)" to avoid crashes
    ft_putstr_fd(str, 1); // Print the string
    len = ft_strlen(str); // Get the length of the printed string
    
    return (len); // Return the total number of printed characters
}

/* Determines the format specifier and prints the corresponding argument */
int ft_print_format(char specifier, va_list args)
{
    if (specifier == 'c') // Print a single character
        return (ft_putchar_fd(va_arg(args, int), 1), 1);
    if (specifier == 's')
    return (ft_print_string(args));
    if (specifier == 'd' || specifier == 'i') // Print an integer
        return (ft_print_int(va_arg(args, int)));
    if (specifier == 'u') // Print an unsigned integer
        return (ft_print_int(va_arg(args, unsigned int)));
    if (specifier == 'x' || specifier == 'X') // Print a hexadecimal number
        return (ft_print_hex(va_arg(args, unsigned int), specifier));
    if (specifier == 'p') // Print a pointer address
        return (ft_print_pointer(va_arg(args, void *)));
    if (specifier == '%') // Print a percent sign
        return (write(1, "%", 1), 1);
    return (0); // Return 0 if no valid format specifier is found
}
