/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:15:37 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/20 00:43:27 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
 * Function: ft_print_format
 * -------------------------
 * Handles different format specifiers used in `ft_printf` and calls the
 * appropriate function to print the corresponding argument.
 *
 * Parameters:
 * - specifier: indicates the data type (e.g., 'd' integer, 's' string).
 * - args: A `va_list` (variable argument list) the values passed to `ft_printf`.
 *
 * Returns:
 * - The number of characters printed.
 *
 * Format Specifiers:
 * - 'c'  -> Prints a single character.
 * - 's'  -> Prints a string.
 * - 'd'  -> Prints a signed integer (same as 'i').
 * - 'i'  -> Prints a signed integer.
 * - 'u'  -> Prints an unsigned integer (no negative values).
 * - 'x'  -> Prints an unsigned integer in lowercase hexadecimal (base 16).
 * - 'X'  -> Prints an unsigned integer in uppercase hexadecimal.
 * - 'p'  -> Prints a pointer address.
 * - '%'  -> Prints the '%' character.
 */
int	ft_print_format(char specifier, va_list args)
{
	char	c;

	if (specifier == 'c')
	{
		c = (char)va_arg(args, int);
		return (write(1, &c, 1));
	}
	if (specifier == 's')
		return (ft_print_string(args));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), specifier));
	if (specifier == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	if (specifier == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
