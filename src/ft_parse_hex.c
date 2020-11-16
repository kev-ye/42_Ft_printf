/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:38:09 by kaye              #+#    #+#             */
/*   Updated: 2020/11/16 21:13:26 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_parse_hex(unsigned int ui, int mode)
{
    char *us;

    us = ft_uitoa_base(ui, 16, mode);
    ft_putstr(us);
    free(us);
}