/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:21:16 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/05 19:24:23 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	%x/%X → liczba w systemie szesnastkowym (małe litery)/(duze litery)
*/

#include "ft_printf.h"


void	ft_print_hex(unsigned int num, size_t *counter, int uppercase)
{
	char	str[9];
	int		i;
	char	*hex;

	hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	if (num == 0)
	{
		ft_putchar_pf('0', counter);
		return;
	}
	i = 0;
	while (num)
	{
		str[i++] = hex[num % 16];
		num /= 16;
	}
	str[i] = '\0';
	while (--i >= 0)
		ft_putchar_pf(str[i], counter);
}