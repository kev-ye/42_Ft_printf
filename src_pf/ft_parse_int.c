/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:28:18 by kaye              #+#    #+#             */
/*   Updated: 2020/11/25 20:05:16 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int with_prec(char *conv, int i, int prec)
{
    int count;
    size_t len;

    count = 0;
    len = ft_strlen(conv);
    if (i < 0 && prec >= 0)
        count += ft_putchar_pf('-');
    if (prec >= 0)
        count += ft_parse_width(prec, len, 1);
    count += ft_putstr_pf(conv);
    return (count);
}

static int parse_int(char *conv, int i, t_flag flag)
{
    int count;
    size_t len;

    count = 0;
    len = ft_strlen(conv);
    if (flag.prec >= 0 && (size_t)flag.prec < len)
        flag.prec = len;
    if (flag.minus)
        count += with_prec(conv, i, flag.prec);
    if (flag.prec >= 0)
        count += ft_parse_width(flag.width, flag.prec, flag.zero);
    else
        count += ft_parse_width(flag.width, len, flag.zero);
    if (!flag.minus)
        count += with_prec(conv, i, flag.prec);
    return (count);
}

int    ft_parse_int(int i, t_flag flag)
{
    char *conv;
    int count;
    int tmp_i;

    count = 0;
    tmp_i = i;
    if (i == 0 && flag.prec == 0)
    {
        count += ft_parse_width(flag.width, 0, 0);
        return (count);
    }
    if (i < 0 && (flag.zero || flag.prec >= 0))
    {
        if (flag.zero == 1 && flag.prec < 0)
            count += ft_putchar_pf('-');
        i *= -1;
        --flag.width;
    }
    conv = ft_itoa_base(i, 10);
    count += parse_int(conv, tmp_i, flag);
    free(conv);
    return (count);
}