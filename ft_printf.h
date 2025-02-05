#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int		ft_printf(const char *str, ...);
void	ft_print_char(char c, size_t *counter);
void	ft_print_string(char *str, size_t *counter);
void	ft_print_int(int n, size_t *counter);
void	ft_print_unsigned(unsigned int nb, size_t *counter);
void	ft_print_hex(unsigned int num, size_t *counter, int uppercase);
void	ft_print_pointer(void *ptr, size_t *counter);
void	ft_putchar_pf(char c, size_t *counter);

#endif
