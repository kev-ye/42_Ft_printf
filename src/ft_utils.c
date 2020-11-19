/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:56:43 by kaye              #+#    #+#             */
/*   Updated: 2020/11/19 19:00:34 by kaye             ###   ########.fr       */
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

int		ft_putchar(char c)
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

int		ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}