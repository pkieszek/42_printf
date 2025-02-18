#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h> // For handling variadic arguments
#include <unistd.h>  // For write function
#include "libft.h"   // Include Libft functions

/* Function Prototypes */
int ft_printf(const char *format, ...);
int ft_print_format(char specifier, va_list args);
int ft_print_hex(unsigned int num, char specifier);
int ft_print_pointer(void *ptr);
int ft_print_string(va_list args);
int ft_print_int(int num);
int ft_print_unsigned(unsigned int num);

#endif /* FT_PRINTF_H */