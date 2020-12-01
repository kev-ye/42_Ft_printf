/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 02:58:51 by kaye              #+#    #+#             */
/*   Updated: 2020/11/30 23:28:21 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void   *type_n(va_list arg, t_flag flag)
// {
//     void *v_n;

//     if (flag.h)
//         v_n = (int *)va_arg(arg, int *);
//     else if (flag.hh)
//         v_n = (char *)va_arg(arg, char *);
//     else if (flag.l)
//         v_n = (long *)va_arg(arg, long *);
//     else if (flag.ll)
//         v_n = va_arg(arg, t_ll *);
//     else
//         v_n = va_arg(arg, int *);
//     return (v_n);
// }

int     ft_parse_int_p(int *i, int count)
{
    *i = count;
    
    return (*i);
}