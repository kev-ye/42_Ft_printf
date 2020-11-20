/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:40:53 by kaye              #+#    #+#             */
/*   Updated: 2020/11/20 16:38:47 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libc.h"
int    ft_parse_string(char *s, t_flag flag)
{
    int count;
    
    count = 0;
    if (!s)
        s = "(null)";
    if (flag.minus)
        count += ft_putstr_pf(s);
    count += ft_parse_width(flag.width, ft_strlen(s), flag.zero);
    if (!flag.minus)
        count += ft_putstr_pf(s);
    return (count);
}