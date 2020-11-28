/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag_plus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:09:52 by kaye              #+#    #+#             */
/*   Updated: 2020/11/28 16:24:41 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_space(t_flag flag)
{
	if (!flag.plus)
		flag.space = 1;
	return (flag);
}

t_flag		ft_plus(t_flag flag)
{
	if (flag.space)
		flag.space = 0;
	flag.plus = 1;
	return (flag);
}
