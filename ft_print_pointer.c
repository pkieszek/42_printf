/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:29:40 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/05 16:41:38 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	%p → wskaźnik w formacie szesnastkowym
*/

#include "ft_printf.h"

static void ft_puthex(unsigned long num, int *count)
{
    char *hex = "0123456789abcdef";

    if (num >= 16)
        ft_puthex(num / 16, count);
    *count += ft_putchar_fd(hex[num % 16], 1);
}

void ft_print_pointer(void *ptr, int *count)
{
    if (!ptr)
    {
        *count += ft_putstr_fd("(nil)", 1);
        return;
    }
    *count += ft_putstr_fd("0x", 1);
    ft_puthex((unsigned long)ptr, count);
}
