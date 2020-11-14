#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int     ft_vprintf(const char *format, va_list arg);
int     ft_type(int type);
void    ft_parse(int type, va_list arg);
void    ft_parse_char(int c);
void    ft_parse_string(char *s);
void    ft_parse_pointer(void *p);
void    ft_parse_int(int i);
void    ft_parse_uint(unsigned int ui);
int     ft_printf(const char *format, ...);

/*
** Utils function
*/

size_t	ft_strlen(const char *s);
void    ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int un);

#endif