/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:39:51 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 18:12:08 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Main ft_printf function that mimics the behavior of printf */
int ft_printf(const char *format, ...)
{
    va_list args;
    int     i;
    int     count;

    va_start(args, format);
    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            count += ft_print_format(format[++i], args);
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}
