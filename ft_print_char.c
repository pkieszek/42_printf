/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:06:31 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/05 19:22:20 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	%c → znak
*/

#include "ft_printf.h"

void	ft_print_char(char c, size_t *counter)
{
	ft_putchar_pf(c, counter);
}