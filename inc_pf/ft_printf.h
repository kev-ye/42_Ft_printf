/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 22:34:03 by kaye              #+#    #+#             */
/*   Updated: 2020/11/28 01:30:42 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define N_LOW 0
# define N_UP 1

typedef struct	s_flag
{
	int	type;
	int width;
	int minus;
	int zero;
	int prec;
	int star;
	int plus;
	int space;
}				t_flag;

/*
** Printf family
*/
int				ft_printf(const char *format, ...);
int				ft_vprintf(const char *format, va_list arg);

/*
** Function process
*/
t_flag			ft_init_flag(void);
int				ft_parse(int type, va_list arg, t_flag flag);
int				ft_process(const char *format, va_list arg);

/*
** Function parse type
*/
int				ft_type(int type);
int				ft_parse_char(int c, t_flag flag);
int				ft_parse_string(char *s, t_flag flag);
int				ft_parse_pointer(void *p, t_flag flag);
int				ft_parse_int(int i, t_flag flag);
int				ft_parse_uint(unsigned int ui, t_flag flag);
int				ft_parse_hex(unsigned int ui, int low_up, t_flag flag);

/*
** Function parse flags
*/
int				ft_flags(int flag);
t_flag			ft_minus(t_flag flag);
t_flag			ft_width(t_flag flag, va_list arg);
t_flag			ft_digit(char format, t_flag flag);
int				ft_prec(const char *format, int begin_value, t_flag *flag,
																va_list arg);
int				ft_parse_width(int width, int hold, int zero);
int				ft_parse_flags(const char *format, int count, t_flag *flag,
																va_list arg);
void			ft_parse_flags_plus(const char *format, int count,
																t_flag **flag);
t_flag			ft_space(t_flag flag);
t_flag			ft_plus(t_flag flag);

/*
** Utils
*/
int				ft_putchar_pf(char c);
size_t			ft_putstr_pf(char *s);
int				ft_putstr_prec_pf(char *s, int prec);

/*
** Convert function
*/
int				ft_conv_dh_pf(int n, int low_up);
size_t			ft_uintlen_base_pf(unsigned int n, int base);
size_t			ft_ulllen_base_pf(unsigned long long n, int base);
char			*ft_uitoa_base_pf(unsigned int un, int base, int low_up);
char			*ft_ulltoa_base_pf(unsigned long long un, int base, int low_up);

#endif
