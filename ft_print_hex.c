/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:26:35 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/20 01:05:56 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
 * Function: ft_puthex
 * -------------------
 * Recursively prints an unsigned integer in hexadecimal format.  
 *
 * Parameters:
 * - num: The unsigned integer to print.  
 * - base: A string containing hexadecimal digits (either lowercase or  
 *   uppercase).  
 *
 * How it works:
 * 1. If the number is greater than or equal to 16, the function calls  
 *    itself recursively with `num / 16`.  
 * 2. This ensures that the most significant digit is printed first.  
 * 3. After recursion, the current digit is printed using `ft_putchar_fd()`.  
 * 4. The `base` string determines whether the output is lowercase (`"x"`)  
 *    or uppercase (`"X"`).  
 *
 * Example:
 * Calling `ft_puthex(42, "0123456789abcdef")` prints `"2a"`.  
 */
static void	ft_puthex(unsigned int num, char *base)
{
	if (num >= 16)
		ft_puthex(num / 16, base);
	ft_putchar_fd(base[num % 16], 1);
}

/*
 * Function: ft_hexlen
 * -------------------
 * Computes the number of characters needed to represent a number  
 * in hexadecimal format.  
 *
 * Parameters:
 * - num: The unsigned integer whose hexadecimal length is calculated.  
 *
 * How it works:
 * 1. Initializes `len` to `1` because every number has at least one digit.  
 * 2. Keeps dividing `num` by `16` and increasing `len` until `num < 16`.  
 * 3. Returns the total length of the hexadecimal representation.  
 *
 * Example:
 * Calling `ft_hexlen(42)` returns `2` because `"2a"` is two characters long.  
 */
static int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 1;
	while (num >= 16)
	{
		num /= 16;
		len++;
	}
	return (len);
}

/*
 * Function: ft_print_hex
 * ----------------------
 * Prints an unsigned integer in hexadecimal format and returns  
 * the number of characters printed.  
 *
 * Parameters:
 * - num: The unsigned integer to print in hexadecimal.  
 * - specifier: Determines if the output should be lowercase ('x') or  
 *   uppercase ('X').  
 *
 * How it works:
 * 1. Selects the correct `base` string based on the `specifier`.  
 * 2. Calls `ft_puthex()` to print the number in hexadecimal format.  
 * 3. Uses `ft_hexlen()` to return the total length of the printed output.  
 *
 * Return:
 * - The number of characters printed.  
 *
 * Example:
 * Calling `ft_print_hex(42, 'x')` prints `"2a"` and returns `2`.  
 */
int	ft_print_hex(unsigned int num, char specifier)
{
	char	*base;

	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_puthex(num, base);
	return (ft_hexlen(num));
}
