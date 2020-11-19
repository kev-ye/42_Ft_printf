/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:03:47 by kaye              #+#    #+#             */
/*   Updated: 2020/11/19 15:53:34 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag      ft_minus(t_flag flag)
{
    flag.minus = 1;
    flag.zero = 0;
    return (flag);
}

t_flag      ft_width(va_list arg, t_flag flag)
{
    flag.star = 1;
    flag.width = va_arg(arg, int);
    if (flag.width < 0)
    {
        flag.minus = 1;
        flag.width *= -1;
    }
    return (flag);
}

t_flag  ft_digit(char format, t_flag flag)
{
    if (flag.star)
        flag.width = 0;
    flag.width = flag.width * 10 + format - '0';
    return (flag);
}