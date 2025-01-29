#include <stdarg.h>
#include <unistd.h>

va_list args;
va_start( args, format);
va_arg( va_list var, type_of_the_variable );
va_end(args);
