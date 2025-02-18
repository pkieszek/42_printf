/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:26:35 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 18:13:15 by pkieszek         ###   ########.fr       */
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

/* Function to print an unsigned integer in hexadecimal format */
int ft_print_hex(unsigned int num, char specifier)
{
    char *base;
    int len;

    base = (specifier == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
    ft_puthex(num, base);
    len = 1;
    while (num /= 16)
        len++;
    return (len);
}
