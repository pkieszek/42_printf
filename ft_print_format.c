/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:15:37 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 20:14:28 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Determines the format specifier and prints the corresponding argument */
int ft_print_format(char specifier, va_list args)
{
if (specifier == 'c')
{
    char c = (char)va_arg(args, int);
    return (write(1, &c, 1));
};
    if (specifier == 's') // Print a string
        return (ft_print_string(args));
    if (specifier == 'd' || specifier == 'i') // Print an integer
        return (ft_print_int(va_arg(args, int)));
    if (specifier == 'u') // Print an unsigned integer
        return (ft_print_unsigned(va_arg(args, unsigned int)));
    if (specifier == 'x' || specifier == 'X') // Print a hexadecimal number
        return (ft_print_hex(va_arg(args, unsigned int), specifier));
    if (specifier == 'p') // Print a pointer address
        return (ft_print_pointer(va_arg(args, void *)));
    if (specifier == '%') // Print a percent sign
        return (write(1, "%", 1), 1);
    return (0); // Return 0 if no valid format specifier is found
}
