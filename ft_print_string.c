/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:05:16 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 20:14:54 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_print_string(va_list args)
{
    char *str;
    int len;

    str = va_arg(args, char *);
    if (!str) // Ensure NULL strings print correctly
        str = "(null)";
    
    ft_putstr_fd(str, 1);
    len = ft_strlen(str);

    return (len);
}
