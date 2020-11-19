/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:05:14 by kaye              #+#    #+#             */
/*   Updated: 2020/11/19 19:44:09 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_parse_width(int width, int zero)
{
    int count;

    count = 0;
    while (width - 1 > 0)
    {
        if (zero)
            ft_putchar('0');
        else
            ft_putchar(' ');
        --width;
        ++count;
    }
    return (count);
}