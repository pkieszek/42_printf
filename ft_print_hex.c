/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:21:16 by pkieszek          #+#    #+#             */
/*   Updated: 2025/01/31 16:47:20 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	%x/%X → liczba w systemie szesnastkowym (małe litery)/(duze litery)
*/

#include "ft_printf.h"

int ft_print_hex(unsigned int num, int uppercase)
{
    char str[8];
    int i = 0;
    char *hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (num == 0)
        return (write(1, "0", 1));

    while (num)
    {
        str[i++] = hex[num % 16];
        num /= 16;
    }

    int len = i;
    while (i--)
        write(1, &str[i], 1);

    return (len);
}