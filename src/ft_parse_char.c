/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:25:38 by kaye              #+#    #+#             */
/*   Updated: 2020/11/19 19:47:19 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_parse_char(int c, t_flag flag)
{
    int count;

    count = 0;
    if (flag.minus)
        ft_putchar(c);
    count = ft_parse_width(flag.width, flag.zero);
    if (!flag.minus)
        ft_putchar(c);
    return (count + 1);
}