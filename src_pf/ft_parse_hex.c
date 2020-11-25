/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:38:09 by kaye              #+#    #+#             */
/*   Updated: 2020/11/25 21:01:49 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int with_prec(char *conv, int prec)
{
    int count;
    size_t len;

    count = 0;
    len = ft_strlen(conv);
    if (prec >= 0)
        count += ft_parse_width(prec, len, 1);
    count += ft_putstr_pf(conv);
    return (count);
}

static int parse_hex(char *conv, t_flag flag)
{
    int count;
    size_t len;

    count = 0;
    len = ft_strlen(conv);
    if (flag.prec >= 0 && (size_t)flag.prec < len)
        flag.prec = len;
    if (flag.minus)
        count += with_prec(conv, flag.prec);
    if (flag.prec >= 0)
        count += ft_parse_width(flag.width, flag.prec, flag.zero);
    else
        count += ft_parse_width(flag.width, len, flag.zero);
    if (!flag.minus)
        count += with_prec(conv, flag.prec);
    return (count);
}

int    ft_parse_hex(unsigned int ui, int low_up, t_flag flag)
{
    char *conv;
    int count;

    count = 0;
    if (ui == 0 && flag.prec == 0)
    {
        count += ft_parse_width(flag.width, 0, 0);
        return (count);
    }
    conv = ft_uitoa_base_pf(ui, 16, low_up);
    count += parse_hex(conv, flag);
    free(conv);
    return (count);
}