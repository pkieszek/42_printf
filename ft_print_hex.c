/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:26:35 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 20:17:27 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Helper function to print a number in hexadecimal format */
static void ft_puthex(unsigned int num, char *base)
{
    if (num >= 16)
        ft_puthex(num / 16, base);
    ft_putchar_fd(base[num % 16], 1);
}

/* Helper function to calculate the length of a hexadecimal number */
static int ft_hexlen(unsigned int num)
{
    int len = 1;
    while (num >= 16)
    {
        num /= 16;
        len++;
    }
    return (len);
}

/* Function to print an unsigned integer in hexadecimal format */
int ft_print_hex(unsigned int num, char specifier)
{
    char *base = (specifier == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
    ft_puthex(num, base);
    return (ft_hexlen(num)); // Ensure correct length is returned
}
