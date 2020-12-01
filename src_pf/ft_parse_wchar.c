/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:16:03 by kaye              #+#    #+#             */
/*   Updated: 2020/11/30 21:16:34 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_wchar(wchar_t c, t_flag flag)
{
	int count;

	count = 0;
	if (flag.minus)
		count += ft_putwchar_pf(c);
	count += ft_parse_width(flag.width, 1, flag.zero);
	if (!flag.minus)
		count += ft_putwchar_pf(c);
	return (count);
}