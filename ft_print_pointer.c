/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:24:42 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 17:49:37 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Helper function to print a number in hexadecimal format */
static void ft_puthex(unsigned long num)
{
    char *hex = "0123456789abcdef";

    if (num >= 16)
        ft_puthex(num / 16);
    ft_putchar_fd(hex[num % 16], 1);
}

/* Helper function to calculate the length of a hexadecimal number */
static int ft_hexlen(unsigned long num)
{
    int len = 1;

    while (num >= 16)
    {
        num /= 16;
        len++;
    }
    return (len);
}

/* Function to print a pointer address and return its length */
int ft_print_pointer(void *ptr)
{
    int len;

    if (!ptr)
        return (ft_putstr_fd("(nil)", 1), 5);
    
    ft_putstr_fd("0x", 1);
    len = 2; // '0x' prefix is always 2 characters long
    ft_puthex((unsigned long)ptr); // Print the memory address in hex

    return (len + ft_hexlen((unsigned long)ptr)); // Return total length
}