/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:40:46 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/18 18:19:54 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_or_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
			c == 'x' || c == 'X' || c == '%')
		return (1);
	else if (c == '.' || c == '*' || c == '0' || c == '-')
		return (2);
	else if (ft_isdigit(c))
		return (3);
	return (0);
}

t_flag			ft_init_static(t_flag flags)
{
	flags.zero = false;
	flags.precision = false;
	flags.minus = false;
	flags.error = false;
	flags.width = false;
	flags.nb_width = 0;
	flags.nb_precisions = 0;
	flags.conv = '?';
	return (flags);
}

t_flag			ft_pars_cases(t_flag flags)
{
	if ((flags.zero && flags.nb_width < 0) ||
			((flags.conv == 'p' || flags.conv == 'c') &&
			(flags.nb_precisions || flags.zero)) ||
			(flags.conv == 's' && flags.zero))
		flags.error = true;
	if (flags.zero && (flags.minus || flags.precision) &&
			(flags.conv == 'd' || flags.conv == 'i' || flags.conv == 'u' ||
			flags.conv == 'x' || flags.conv == 'X'))
		flags.zero = false;
	return (flags);
}
