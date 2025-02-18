/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:39:51 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 18:07:07 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Converts an integer to a string, prints it, and returns its length */
static int ft_print_int(int num)
{
    char *str;
    int len;

    str = ft_itoa(num);
    if (!str)
        return (0);
    len = ft_strlen(str);
    ft_putstr_fd(str, 1);
    free(str);
    return (len);
}

/* Converts an unsigned integer to a string, prints it, and returns its length */
static int ft_print_unsigned(unsigned int num)
{
    char *str;
    int len;

    str = ft_itoa(num);
    if (!str)
        return (0);
    len = ft_strlen(str);
    ft_putstr_fd(str, 1);
    free(str);
    return (len);
}

/* Determines the format specifier and prints the corresponding argument */
int ft_print_format(char specifier, va_list args)
{
    if (specifier == 'c')
        return (ft_putchar_fd(va_arg(args, int), 1), 1);
    if (specifier == 's')
        return (ft_print_string(args));
    if (specifier == 'd' || specifier == 'i')
        return (ft_print_int(va_arg(args, int)));
    if (specifier == 'u')
        return (ft_print_unsigned(va_arg(args, unsigned int)));
    if (specifier == 'x' || specifier == 'X')
        return (ft_print_hex(va_arg(args, unsigned int), specifier));
    if (specifier == 'p')
        return (ft_print_pointer(va_arg(args, void *)));
    if (specifier == '%')
        return (write(1, "%", 1), 1);
    return (0);
}
