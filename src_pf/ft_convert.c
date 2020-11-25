/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:58:04 by kaye              #+#    #+#             */
/*   Updated: 2020/11/25 23:46:53 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_uitoa_base_pf(unsigned int un, int base, int low_up)
{
	size_t			len;
	char			*str;

	len = ft_uintlen_base_pf(un, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = ft_conv_dh_pf((un % base), low_up);
		un /= base;
	}
	return (str);
}

char			*ft_ulltoa_base_pf(unsigned long long un, int base, int low_up)
{
	size_t			len;
	char			*str;

	len = ft_ulllen_base_pf(un, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = ft_conv_dh_pf((un % base), low_up);
		un /= base;
	}
	return (str);
}