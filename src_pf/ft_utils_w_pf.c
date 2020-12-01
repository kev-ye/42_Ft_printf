/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_w_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:20:30 by kaye              #+#    #+#             */
/*   Updated: 2020/11/30 21:51:17 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_strwlen(wchar_t *s)
{
    wchar_t *tmp_s;

    tmp_s = s;
    while (*tmp_s)
        ++tmp_s;
    return (tmp_s - s);
}

int		ft_putwchar_pf(wchar_t c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putwstr_pf(wchar_t *s)
{
	size_t len;

	if (!s)
		return (0);
    len = 0;
    while (s[len])
        ft_putwchar_pf(s[len++]);
	return (len);
}

int		ft_putwstr_prec_pf(wchar_t *s, int prec)
{
	int count;

	count = 0;
	while (s[count] && count < prec)
		(void)ft_putwchar_pf(s[count++]);
	return (count);
}