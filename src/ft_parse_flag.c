/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:03:47 by kaye              #+#    #+#             */
/*   Updated: 2020/11/19 21:12:32 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libc.h>

t_flag      ft_minus(t_flag flag)
{
    flag.minus = 1;
    flag.zero = 0;
    return (flag);
}

t_flag      ft_width(t_flag flag, va_list arg)
{
    flag.star = 1;
    flag.width = va_arg(arg, int);
    if (flag.width < 0)
    {
        flag.minus = 1;
        flag.zero = 0;
        flag.width *= -1;
    }
    return (flag);
}

t_flag  ft_digit(char format, t_flag flag)
{
    if (flag.star)
        return (flag);
    flag.width = flag.width * 10 + format - '0';
    return (flag);
}

int     ft_prec(const char *format, int begin_value, t_flag *flag, va_list arg)
{
    if (format[begin_value] == '*')
    {
        flag->prec = va_arg(arg, int);
        begin_value++;
    }
    else
    {
        flag->prec = 0;
        while (ft_isdigit(format[begin_value]))
            flag->prec = flag->prec * 10 + format[begin_value++] - '0';
    }
    return (begin_value);
}