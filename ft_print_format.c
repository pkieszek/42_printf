/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:15:37 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/19 02:13:05 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
 * Determines the format specifier and prints the corresponding argument.
 */
int	ft_print_format(char specifier, va_list args)
{
	char	c;

	if (specifier == 'c')
	{
		c = (char)va_arg(args, int);
		return (write(1, &c, 1));
	}
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
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
