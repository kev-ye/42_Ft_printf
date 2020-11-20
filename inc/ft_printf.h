#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_flag
{
    int type;
    int width;
    int minus;
    int zero;
    int prec;
    int star;
}              t_flag;

/*
** Function regroup
*/

t_flag  ft_int_flag(void);
int     ft_parse(int type, va_list arg, t_flag flag);
int     ft_vprintf(const char *format, va_list arg);
int     ft_printf(const char *format, ...);

/*
** Function parse type
*/

int     ft_type(int type);
int     ft_parse_char(int c, t_flag flag);
int     ft_parse_string(char *s, t_flag flag);;
void    ft_parse_pointer(void *p);
void    ft_parse_int(int i);
void    ft_parse_uint(unsigned int ui);
void    ft_parse_hex(unsigned int ui, int mode);
void    ft_parse_percent(void);

/*
** Function parse flags
*/

int     ft_flags(int flag);
t_flag  ft_minus(t_flag flag);
t_flag  ft_width(t_flag flag, va_list arg);
t_flag  ft_digit(char format, t_flag flag);
int     ft_prec(const char *format, int begin_value, t_flag *flag, va_list arg);
int     ft_parse_width(int width, int hold, int zero);
int     ft_parse_flags(const char *format, int count, t_flag *flag, va_list arg);


/*
** Utils
*/

size_t	ft_strlen(const char *s);
int     ft_putchar_pf(char c);
void	ft_putstr(char *s);
size_t	ft_putstr_pf(char *s);
int		ft_putstr_prec_pf(char *s, int prec);
int		ft_isdigit(int c);

/*
** Convert function
*/
int     ft_conv_dh(int n, int mode);
size_t	ft_intlen_base(int n, int base);
size_t	ft_uintlen_base(unsigned int n, int base);
size_t	ft_ulllen_base(unsigned long long n, int base);
char	*ft_itoa_base(int n, int base, int mode);
char	*ft_uitoa_base(unsigned int un, int base, int mode);
char	*ft_ulltoa_base(unsigned long long un, int base, int mode);

#endif