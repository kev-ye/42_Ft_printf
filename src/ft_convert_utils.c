/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:14:12 by kaye              #+#    #+#             */
/*   Updated: 2020/11/16 21:09:51 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen_base(int n, int base)
{
	size_t count;

	count = (n) ? 0 : 1;
	while (n)
	{
		n = n / base;
		++count;
	}
	return (count);
}

size_t	ft_uintlen_base(unsigned int n, int base)
{
	size_t count;

	count = (n) ? 0 : 1;
	while (n)
	{
		n = n / base;
		++count;
	}
	return (count);
}

size_t	ft_ulllen_base(unsigned long long n, int base)
{
	size_t count;

	count = (n) ? 0 : 1;
	while (n)
	{
		n = n / base;
		++count;
	}
	return (count);
}

int      ft_conv_dh(int n, int mode)
{
    if (n < 10)
        return (n + '0');
    else
    {
        return ((mode) ? (n - 10 + 'A') : (n - 10 + 'a'));
    }
}