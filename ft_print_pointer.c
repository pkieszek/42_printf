/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:29:40 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/05 19:25:23 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	%p → wskaźnik w formacie szesnastkowym
*/

#include "ft_printf.h"

static void	ft_print_hex_ptr(unsigned long num, size_t *counter)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num >= 16)
		ft_print_hex_ptr(num / 16, counter);
	ft_putchar_pf(hex[num % 16], counter);
}

void	ft_print_pointer(void *ptr, size_t *counter)
{
	if (!ptr)
	{
		ft_print_string("(nil)", counter);
		return;
	}
	ft_print_string("0x", counter);
	ft_print_hex_ptr((unsigned long)ptr, counter);
}
