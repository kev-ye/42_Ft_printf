/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:56:18 by kaye              #+#    #+#             */
/*   Updated: 2020/11/14 20:19:54 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_print_hex(unsigned char addr)
{
    char *hex;

    hex = "0123456789abcdef";
    ft_putchar(hex[addr / 16]);
    ft_putchar(hex[addr % 16]);
}

void    ft_parse_pointer(void *p)
{
    int i;

    i = 40;
    ft_putstr("0x");
    while (i >= 0)
    {
        ft_print_hex(((unsigned long long)p) >> i);
        i -= 8;
    }
}