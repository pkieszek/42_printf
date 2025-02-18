/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:39:51 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 17:47:31 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // Include the ft_printf header file
#include "libft.h" // Include the libft header file for helper functions
#include <stdarg.h> // Include stdarg.h to handle variadic functions

/* Function to process the format specifier and print the appropriate argument */
int  ft_print_format(char specifier, va_list args)
{
    if (specifier == 'c') // Print a single character
        return (ft_putchar_fd(va_arg(args, int), 1), 1);
    if (specifier == 's') // Print a string
        return (ft_putstr_fd(va_arg(args, char *), 1), ft_strlen(va_arg(args, char *)));
    if (specifier == 'd' || specifier == 'i') // Print an integer (decimal)
        return (ft_putnbr_fd(va_arg(args, int), 1), ft_strlen(ft_itoa(va_arg(args, int))));
    if (specifier == 'u') // Print an unsigned integer
        return (ft_putnbr_fd(va_arg(args, unsigned int), 1), ft_strlen(ft_itoa(va_arg(args, unsigned int))));
    if (specifier == 'x' || specifier == 'X') // Print a hexadecimal number (lower/uppercase)
        return (ft_print_hex(va_arg(args, unsigned int), specifier));
    if (specifier == 'p') // Print a pointer address
        return (ft_print_pointer(va_arg(args, void *)));
    if (specifier == '%') // Print a percent sign
        return (write(1, "%", 1), 1);
    return (0); // Return 0 if no valid format specifier is found
}

/* Main ft_printf function that mimics the behavior of printf */
int ft_printf(const char *format, ...)
{
    va_list args; // Declare the argument list
    int     i; // Index for traversing format string
    int     count; // Counter to keep track of printed characters

    va_start(args, format); // Initialize the argument list
    i = 0;
    count = 0;
    while (format[i]) // Loop through the format string
    {
        if (format[i] == '%' && format[i + 1]) // Check for format specifier
        {
            count += ft_print_format(format[++i], args); // Process the format specifier
        }
        else // Print normal characters
        {
            write(1, &format[i], 1);
            count++;
        }
        i++; // Move to the next character
    }
    va_end(args); // Clean up argument list
    return (count); // Return total number of characters printed
}
