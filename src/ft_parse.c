/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:27:15 by kaye              #+#    #+#             */
/*   Updated: 2020/11/14 20:53:52 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_type(int type)
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
    return (0);
}

void     ft_parse(int type, va_list arg)
{
    if (type == 'c')
        ft_parse_char(va_arg(arg, int));
    if (type == 's')
        ft_parse_string(va_arg(arg, char *));
    if (type == 'p')
        ft_parse_pointer(va_arg(arg, void *));
    if (type == 'd' || type == 'i')
        ft_parse_int(va_arg(arg, int));
    if (type == 'u')
        ft_parse_uint(va_arg(arg, unsigned int));
}