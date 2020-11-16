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
void    ft_parse_hex(unsigned int ui, int mode);
void    ft_parse_percent(void);
int     ft_printf(const char *format, ...);

/*
** Utils
*/

size_t	ft_strlen(const char *s);
void    ft_putchar(char c);
void	ft_putstr(char *s);

/*
** Convert function
*/
int      ft_conv_dh(int n, int mode);
size_t	ft_intlen_base(int n, int base);
size_t	ft_uintlen_base(unsigned int n, int base);
size_t	ft_ulllen_base(unsigned long long n, int base);
char	*ft_itoa_base(int n, int base, int mode);
char	*ft_uitoa_base(unsigned int un, int base, int mode);
char	*ft_ulltoa_base(unsigned long long un, int base, int mode);

#endif