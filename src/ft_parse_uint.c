/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:44:55 by kaye              #+#    #+#             */
/*   Updated: 2020/11/16 21:18:17 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_parse_uint(unsigned int ui)
{
    char *conv;

    conv = ft_uitoa_base(ui, 10, 0);
    ft_putstr(conv);
    free(conv);
}