/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 16:33:30 by rkowalsk     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 16:30:39 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_param(va_list params, char conv)
{
	t_param param;

	if (conv == 'c')
	{
		ft_putchar_fd(va_arg(params, int), 1);
		return (1);
	}
	else if (conv == 's')
	{
		param.str = va_arg(params, char*);
		ft_putstr_fd(param.str, 1);
		return (ft_strlen(param.str));
	}
	else if (conv == 'd' || conv == 'i')
	{
		param.str = ft_itoa(va_arg(params, int));
		ft_putstr_fd(param.str, 1);
		return (ft_strlen(param.str));
	}
	else if (conv == 'u')
	{
		param.str = ft_uitoa(va_arg(params, unsigned int));
		ft_putstr_fd(param.str, 1);
		return (ft_strlen(param.str));
	}
	else if (conv == 'x')
	{
		param.str = ft_uitox_lowercase(va_arg(params, unsigned int));
		ft_putstr_fd(param.str, 1);
		return (ft_strlen(param.str));
	}
	else if (conv == 'X')
	{
		param.str = ft_uitox_uppercase(va_arg(params, unsigned int));
		ft_putstr_fd(param.str, 1);
		return (ft_strlen(param.str));
	}
	else if (conv == 'p')
	{
		param.str = ft_uitox_lowercase(va_arg(params, uintptr_t));
		param.str = ft_strjoin("0x", param.str);
		ft_putstr_fd(param.str, 1);
		return (ft_strlen(param.str));
	}
	else if (conv == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (-1);
}

int		ft_printf(const char *str, ...)
{
	va_list params;
	size_t	i;
	int		ret;

	va_start(params, str);
	ret = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
			ret = ret + ft_print_param(params, str[++i]);
		else
		{
			ft_putchar_fd(str[i], 1);
			ret++;
		}
		i++;
	}
	va_end(params);
	return (ret);
}
