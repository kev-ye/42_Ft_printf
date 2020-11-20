/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:56:43 by kaye              #+#    #+#             */
/*   Updated: 2020/11/20 15:52:29 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	const char *str;

	str = s;
	while (*str)
		++str;
	return (str - s);
}

int		ft_putchar_pf(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

size_t	ft_putstr_pf(char *s)
{
	size_t len;

	len = ft_strlen(s);
	if (!s)
		return (0);
	write(1, s, len);
	return (len);
}

int		ft_putstr_prec_pf(char *s, int prec)
{
		int count;

		count = 0;
		while (s[count] && count < prec)
			(void)ft_putchar_pf(s[count++]);
		return (count);
}

int		ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
