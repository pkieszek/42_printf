#include <stdarg.h>
#include <unistd.h>
#include <libft.h>

int ft_printf(const char *str, ...);
void ft_print_char(char c);
void ft_print_string(char *str, size_t *counter);
void ft_print_int(int n);
void ft_print_unsigned(unsigned int nb);
void ft_print_hex(unsigned int num, int uppercase);
void ft_print_pointer(void *ptr, int *count);

#endif