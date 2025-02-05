/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:27:08 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/05 19:23:49 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	%u → liczba całkowita (base 10), unsigned integer
*/

#include "ft_printf.h"


static void	ft_print_unsigned_recursive(unsigned int nb, size_t *counter)
{
	if (nb > 9)
		ft_print_unsigned_recursive(nb / 10, counter);
	ft_putchar_pf((nb % 10) + '0', counter);
}

void	ft_print_unsigned(unsigned int nb, size_t *counter)
{
	ft_print_unsigned_recursive(nb, counter);
}