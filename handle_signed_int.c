/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:25:24 by pkieszek          #+#    #+#             */
/*   Updated: 2025/01/31 16:22:17 by pkieszek         ###   ########.fr       */
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

    num_str = ft_itoa(n); // Convert integer to string
    if (!num_str)
        return (0);

    ft_putstr_fd(num_str, 1); // Print the string
    len = ft_strlen(num_str); // Get the printed length
    free(num_str); // Free the allocated memory

    return (len);
}