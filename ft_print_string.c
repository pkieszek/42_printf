/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:05:16 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/20 00:57:31 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
 * Function: ft_print_string
 * -------------------------
 * This function retrieves a string argument from the variadic list and prints  
 * it to the standard output. It is part of the custom printf implementation.  
 *
 * Parameters:
 * - args: A `va_list` containing the arguments passed to `ft_printf`.  
 *
 * How it works:
 * 1. The function extracts the next argument as a string using `va_arg()`.  
 * 2. If the argument is `NULL`, it substitutes it with "(null)".  
 * 3. The string is printed using `ft_putstr_fd()`.  
 * 4. Function returns the length of the printed string using `ft_strlen()`.  
 *
 * Return:
 * - The total number of characters printed.  
 *
 * Example:
 * Calling `ft_print_string(args)` when the argument is `"Hello"`  
 * prints `"Hello"` and returns `5`.  
 */
int	ft_print_string(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	return (len);
}
