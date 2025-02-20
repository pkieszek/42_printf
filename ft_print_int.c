/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:00:44 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/20 01:03:11 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
 * Function: ft_print_int
 * ----------------------
 * Converts an integer to a string, prints it, and returns its length.  
 *
 * Parameters:
 * - num: The integer to be printed.  
 *
 * How it works:
 * 1. Calls `ft_itoa()` to convert the integer into a dynamically allocated  
 *    string representation.  
 * 2. If `ft_itoa()` fails and returns `NULL`, the function immediately  
 *    returns `0` to indicate failure.  
 * 3. Calls `ft_strlen()` to determine the length of the string.  
 * 4. Prints the string using `ft_putstr_fd()`.  
 * 5. Frees the dynamically allocated memory to avoid memory leaks.  
 * 6. Returns the number of characters printed.  
 *
 * Return:
 * - The number of characters printed.  
 *
 * Example:
 * Calling `ft_print_int(42);` prints `"42"` and returns `2`.  
 */
int	ft_print_int(int num)
{
	char	*str;
	int		len;

	str = ft_itoa(num);
	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
