/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:01:12 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/20 00:59:36 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
 * Function: ft_utoa
 * -----------------
 * Converts an unsigned integer to a string. This is similar to `itoa`,  
 * but specifically for unsigned integers, ensuring that negative values  
 * are not handled (since they are not possible).  
 *
 * Parameters:
 * - num: The unsigned integer to be converted to a string.  
 *
 * How it works:
 * 1. A character buffer (`buffer`) is used to store the string representation.  
 * 2. The buffer is indexed from the end, filling in digits from right to left.  
 * 3. Each digit is extracted using modulo (`% 10`) and converted to a char.  
 * 4. The loop continues until the number is reduced to a single digit.  
 * 5. The resulting string is duplicated using `ft_strdup()` and returned.  
 *
 * Return:
 * - A newly allocated string containing the converted number.  
 *
 * Example:
 * Calling `ft_utoa(1234)` returns `"1234"`.  
 */
char	*ft_utoa(unsigned int num)
{
	char	buffer[20];
	int		i;

	i = 19;
	buffer[i] = '\0';
	while (num >= 10)
	{
		buffer[--i] = (num % 10) + '0';
		num /= 10;
	}
	buffer[--i] = num + '0';
	return (ft_strdup(&buffer[i]));
}

/*
 * Function: ft_print_unsigned
 * ---------------------------
 * Prints an unsigned integer and returns the number of characters printed.  
 *
 * Parameters:
 * - num: The unsigned integer to print.  
 *
 * How it works:
 * 1. Calls `ft_utoa()` to convert the number into a string.  
 * 2. Uses `ft_strlen()` to determine the length of the string.  
 * 3. Prints the string using `ft_putstr_fd()`.  
 * 4. Frees the allocated memory to prevent memory leaks.  
 * 5. Returns the length of the printed string.  
 *
 * Return:
 * - The number of characters printed.  
 *
 * Example:
 * Calling `ft_print_unsigned(42);` prints `"42"` and returns `2`.  
 */
int	ft_print_unsigned(unsigned int num)
{
	char	*str;
	int		len;

	str = ft_utoa(num);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
