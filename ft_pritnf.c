/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pritnf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:39:51 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/05 19:21:12 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

static void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_print_char(va_arg(va, int), counter);
	else if (*str == 's')
		ft_print_string(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_print_pointer(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_print_int(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_print_unsigned(va_arg(va, unsigned int), counter);
	else if (*str == 'x' || *str == 'X')
		ft_print_hex(va_arg(va, unsigned int), counter, (*str == 'X'));
	else if (*str == '%')
		ft_putchar_pf('%', counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va, (char *)str, &counter);
		}
		else
			ft_putchar_pf(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}