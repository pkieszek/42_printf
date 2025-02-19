/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:39:51 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/20 00:54:39 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
 * Function: ft_printf
 * -------------------
 * A custom implementation of the standard printf function in C. It takes  
 * a format string and a variable number of arguments to print formatted  
 * output to the standard output (stdout).  
 *
 * Parameters:
 * - format: A constant string containing text and format specifiers.  
 *           Format specifiers begin with '%' and define how the  
 *           corresponding argument should be printed (e.g., %d for integers,  
 *           %s for strings).
 * - ... (variadic arguments): Additional arguments matching format specifiers.  
 *
 * How it works:
 * 1. Initializes a `va_list` to handle variadic arguments.  
 * 2. Iterates through the format string, processing each character.  
 * 3. If '%' is found, the next character determines how to print the argument.  
 * 4. Calls `ft_print_format` to handle formatted output.  
 * 5. Otherwise, prints the character directly to the output.  
 * 6. Counts the total number of printed characters.  
 * 7. Ends the `va_list` to release resources.  
 * 8. Returns the total number of characters printed.  
 *
 * Return:
 * - The total number of characters printed.  
 *
 * Example:
 * Calling `ft_printf("Hello %s, number: %d", "Luigi", 42);`  
 * prints `"Hello Luigi, number: 42"` and returns `22`.  
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_print_format(format[++i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
