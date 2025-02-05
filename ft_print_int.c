/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:25:24 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/05 17:30:17 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	%i/%d → liczba całkowita (base 10), signed integers
*/

#include "ft_printf.h"

int ft_print_int(int n)
{
    char *num_str;
    int len;

    num_str = ft_itoa(n);
    if (!num_str)
        return (0);

    ft_putstr_fd(num_str, 1);
    len = ft_strlen(num_str);
    free(num_str)

    return (len);
}