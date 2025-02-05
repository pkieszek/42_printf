/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:08:49 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/05 17:17:58 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	%s → string
*/

#include "ft_printf.h"

void	ft_print_string(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_fd(*str, counter);
		str++;
	}
}