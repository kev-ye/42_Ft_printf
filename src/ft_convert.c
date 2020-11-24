/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:58:04 by kaye              #+#    #+#             */
/*   Updated: 2020/11/23 21:31:23 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_base(int n, int base, int mode)
{
	size_t			len;
	char			*str;
	unsigned int	n_tmp;

	n_tmp = (n < 0) ? -(unsigned int)n : n;
	len = (n < 0) ? ft_intlen_base(n_tmp, base) + 1 : ft_intlen_base(n_tmp, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = ft_conv_dh((n_tmp % base), mode);
		n_tmp /= base;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char			*ft_uitoa_base(unsigned int un, int base, int mode)
{
	size_t			len;
	char			*str;

	len = ft_uintlen_base(un, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = ft_conv_dh((un % base), mode);
		un /= base;
	}
	return (str);
}

char			*ft_ulltoa_base(unsigned long long un, int base, int mode)
{
	size_t			len;
	char			*str;

	len = ft_ulllen_base(un, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = ft_conv_dh((un % base), mode);
		un /= base;
	}
	return (str);
}