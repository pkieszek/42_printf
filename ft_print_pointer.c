/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:24:42 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 17:24:55 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Helper function to print a number in hexadecimal format */
static void ft_puthex(unsigned long num)
{
    char *hex;

    hex = "0123456789abcdef";
    if (num >= 16)
        ft_puthex(num / 16);
    ft_putchar_fd(hex[num % 16], 1);
}

/* Function to print a pointer address and return its length */
int ft_print_pointer(void *ptr)
{
    int len;

    if (!ptr) // Handle NULL pointer case
        return (ft_putstr_fd("(nil)", 1), 5);
    len = ft_putstr_fd("0x", 1); // Print the '0x' prefix
    ft_puthex((unsigned long)ptr); // Print the memory address in hex
    return (len + ft_strlen(ft_itoa_base((unsigned long)ptr, 16))); // Return total length
}
