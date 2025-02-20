/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:24:42 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/20 01:01:20 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
 * Function: ft_puthex
 * -------------------
 * Recursively prints a number in lowercase hexadecimal format.  
 *
 * Parameters:
 * - num: The unsigned long number to be printed in hexadecimal.  
 *
 * How it works:
 * 1. The hexadecimal digits are stored in a string `"0123456789abcdef"`.  
 * 2. If the number is 16 or greater, the function calls itself recursively  
 *    to print the higher-order digits first.  
 * 3. The least significant digit is printed using `ft_putchar_fd()`.  
 *
 * Example:
 * Calling `ft_puthex(42)` prints `"2a"`.  
 */
static void	ft_puthex(unsigned long num)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num >= 16)
		ft_puthex(num / 16);
	ft_putchar_fd(hex[num % 16], 1);
}

/*
 * Function: ft_hexlen
 * -------------------
 * Computes the length of a number when represented in hexadecimal.  
 *
 * Parameters:
 * - num: The unsigned long number to measure.  
 *
 * How it works:
 * 1. The function starts with `len = 1`, since every number has at  
 *    least one digit.  
 * 2. It repeatedly divides the number by 16, increasing `len` each  
 *    time, until the number is smaller than 16.  
 *
 * Return:
 * - The number of characters required to represent `num` in hexadecimal.  
 *
 * Example:
 * Calling `ft_hexlen(42)` returns `2` because `"2a"` is two characters long.  
 */
static int	ft_hexlen(unsigned long num)
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
 * Function: ft_print_pointer
 * --------------------------
 * Prints a memory address in hexadecimal format with the `0x` prefix.  
 *
 * Parameters:
 * - ptr: A pointer to be printed.  
 *
 * How it works:
 * 1. If `ptr` is `NULL`, it prints `"(nil)"` and returns `5` (the length).  
 * 2. Otherwise, it prints `"0x"` to indicate a hexadecimal memory address.  
 * 3. It calls `ft_puthex()` to print the pointer's address as a hexadecimal  
 *    number.  
 * 4. The function calculates the total length (2 for `"0x"` + the hex digits)  
 *    and returns it.  
 *
 * Return:
 * - The total number of characters printed.  
 *
 * Example:
 * Calling `ft_print_pointer((void *)42)` prints `"0x2a"` and returns `4`.  
 */
int	ft_print_pointer(void *ptr)
{
	int	len;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_puthex((unsigned long)ptr);
	len = 2 + ft_hexlen((unsigned long)ptr);
	return (len);
}
