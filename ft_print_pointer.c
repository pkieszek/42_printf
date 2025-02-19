/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:24:42 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/19 02:15:51 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
 * Helper function to print a number in hexadecimal format.
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
 * Helper function to calculate the length of a hexadecimal number.
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
 * Function to print a pointer in hexadecimal format.
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
