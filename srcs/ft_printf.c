/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:33:52 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/12 16:34:00 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conv_or_flag(char c)
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

t_flag		init_static(t_flag flags)
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

t_flag		ft_pars_flags(va_list params, char *str)
{
	static t_flag	flags;
	int				ret;
	int				i;

	flags = init_static(flags);
	i = 0;
	while (str[i] && (ret = conv_or_flag(str[i])) != 1)
	{
		if (ret == 0)
		{
			flags.error = true; // à vérifier dans la fonction mère ERRARE HUMANUM EST
			return (flags);
		}
		else if (str[i] == '-')
		{
			flags.minus = true;
			i++;
		}
		else if (str[i] == '0')
		{
			flags.zero = true;
			i++;
		}
		else if (str[i] == '*')
		{ 
			if (flags.width == true)
			{
				flags.error = true;
				return (flags);
			}
			flags.nb_width = va_arg(params, int);
			if (flags.nb_width < 0)
			{
				flags.minus = true;
				flags.nb_width = -flags.nb_width;
			}
			flags.width = true;
			i++;
		}
		else if (ft_isdigit(str[i]))
		{
			if (flags.width == true)
			{
				flags.error = true;
				return (flags);
			}
			flags.width = true;
			flags.nb_width = ft_atoi(str + i);
			while(ft_isdigit(str[i]))
				i++;
		}
		else if (str[i] == '.')
		{
			if (flags.precision == true)
			{
				flags.error = true;
				return (flags);
			}
			flags.precision = true;
			if (str[++i] == '*')
			{
				flags.nb_precisions = va_arg(params, int);
				if (flags.nb_precisions < 0)
					flags.precision = false;
				i++;
			}
			else
			{
				if (str[i] == '-')
				{
					flags.error = true;
					return (flags);
				}
				flags.nb_precisions = ft_atoi(str + i);
				while(ft_isdigit(str[i]))
					i++;
			}
		}
	}
	flags.conv = str[i];
	if ((flags.zero && flags.nb_width < 0) ||
	((flags.conv == 'p' || flags.conv == 'c' || flags.conv == '%') &&
	(flags.nb_precisions || flags.zero))|| (flags.conv == 's' && flags.zero))
		flags.error = true;
	if (flags.zero && flags.precision &&
	(flags.conv == 'd' || flags.conv == 'i'	|| flags.conv == 'u' ||
	flags.conv == 'x' || flags.conv == 'X'))
		flags.zero = false;
	return (flags);
}

int		ft_printf(const char *str, ...)
{
	va_list params;
	size_t	i;
	int		size;
	int		ret;
	t_flag flags;

	va_start(params, str);
	size = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			flags = ft_pars_flags(params, (char *)str + ++i);
			//dprintf(1, "error : %d\nzero : %d\nprecision : %d\nminus : %d\nwidth :  %d\nnb_width : %d\nnb_precisions : %d\nconv : %c\n", flags.error, flags.zero, flags.precision, flags.minus, flags.width, flags.nb_width, flags.nb_precisions, flags.conv);
			if (flags.error || (ret = ft_print_param(params, flags)) == -1)
				return (-1);
			size += ret;
			while (conv_or_flag(str[i]) != 1)
				i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			size++;
		}
		i++;
	}
	va_end(params);
	return (size);
}
