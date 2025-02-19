/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:19:30 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/19 02:19:49 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // Variadic arguments
# include <unistd.h> // write function
# include "libft.h"  // Include Libft functions

/* Function Prototypes */
int	ft_printf(const char *format, ...);
int	ft_print_format(char specifier, va_list args);
int	ft_print_hex(unsigned int num, char specifier);
int	ft_print_pointer(void *ptr);
int	ft_print_string(va_list args);
int	ft_print_int(int num);
int	ft_print_unsigned(unsigned int num);

#endif /* FT_PRINTF_H */