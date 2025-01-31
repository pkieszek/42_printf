/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:08:49 by pkieszek          #+#    #+#             */
/*   Updated: 2025/01/31 16:14:39 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	%s → string
*/

#include "ft_printf.h"

int ft_print_string(char *str)
{
    int len;

    if (!str)
        str = "(null)";

    len = ft_strlen(str);
	
    ft_putstr_fd(str, 1);

    return (len);
} 