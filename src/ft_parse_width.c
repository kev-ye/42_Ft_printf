/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:05:14 by kaye              #+#    #+#             */
/*   Updated: 2020/11/23 17:28:45 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_parse_width(int width, int hold, int zero)
{
    int count;

    count = 0;
    while (width - hold > 0)
    {
        if (zero)
            ft_putchar_pf('0');
        else
            ft_putchar_pf(' ');
        --width;
        ++count;
    }
    return (count);
}