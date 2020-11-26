/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:27:15 by kaye              #+#    #+#             */
/*   Updated: 2020/11/26 23:24:06 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(int type)
{
	if (type == 'c')
		return (1);
	else if (type == 's')
		return (1);
	else if (type == 'p')
		return (1);
	else if (type == 'd' || type == 'i')
		return (1);
	else if (type == 'u')
		return (1);
	else if (type == 'x')
		return (1);
	else if (type == 'X')
		return (1);
	else if (type == '%')
		return (1);
	return (0);
}

int		ft_flags(int flag)
{
	if (flag == '-')
		return (1);
	else if (flag == '0')
		return (1);
	else if (flag == '.')
		return (1);
	else if (flag == '*')
		return (1);
	return (0);
}

int		ft_parse_flags(const char *format, int count, t_flag *flag, va_list arg)
{
	while (format[count])
	{
		if (!ft_isdigit(format[count]) && !ft_type(format[count]) &&
			!ft_flags(format[count]))
			break ;
		if (format[count] == '0' && flag->minus == 0 && flag->width == 0)
			flag->zero = 1;
		if (format[count] == '.')
			count = ft_prec(format, ++count, flag, arg);
		if (format[count] == '-')
			*flag = ft_minus(*flag);
		if (format[count] == '*')
			*flag = ft_width(*flag, arg);
		if (ft_isdigit(format[count]))
			*flag = ft_digit(format[count], *flag);
		if (ft_type(format[count]))
		{
			flag->type = format[count];
			break ;
		}
		++count;
	}
	return (count);
}

int		ft_parse(int type, va_list arg, t_flag flag)
{
	int count;

	count = 0;
	if (type == 'c')
		count = ft_parse_char(va_arg(arg, int), flag);
	else if (type == 's')
		count = ft_parse_string(va_arg(arg, char *), flag);
	else if (type == 'p')
		count = ft_parse_pointer(va_arg(arg, void *), flag);
	else if (type == 'd' || type == 'i')
		count = ft_parse_int(va_arg(arg, int), flag);
	else if (type == 'u')
		count = ft_parse_uint(va_arg(arg, unsigned int), flag);
	else if (type == 'x')
		count = ft_parse_hex(va_arg(arg, unsigned int), N_LOW, flag);
	else if (type == 'X')
		count = ft_parse_hex(va_arg(arg, unsigned int), N_UP, flag);
	else if (type == '%')
		count = ft_parse_char('%', flag);
	return (count);
}
