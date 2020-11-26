/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:14:12 by kaye              #+#    #+#             */
/*   Updated: 2020/11/25 21:01:35 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_uintlen_base_pf(unsigned int n, int base)
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

size_t	ft_ulllen_base_pf(unsigned long long n, int base)
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

int		ft_conv_dh_pf(int n, int low_up)
{
	if (n < 10)
		return (n + '0');
	else
		return ((low_up) ? (n - 10 + 'A') : (n - 10 + 'a'));
}
